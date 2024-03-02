#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// DATA
void BitcoinExchange::makeDataMap(std::string& dataFileName)
{
	std::fstream fData(dataFileName.c_str());
	if (fData.is_open())
	{
		std::string str;
		std::string target = ",";
		if (fData >> str)
		{
			if (str != "date,exchange_rate")
				throw std::invalid_argument("Error: This datafile is invalid (first string)");
		}
		while (fData >> str)
		{
			_data.insert(split(str, target));
		}
		fData.close();
	}
	else
	{
		throw std::invalid_argument("Error: This datafile is can't open");
	}

	if (_data.size() == 0)
	{
		throw std::invalid_argument("Error: This datafile is empty");
	}
}

// INPUT
bool BitcoinExchange::isCSVFile(std::string fileName)
{
	if (fileName.length() < 4)
	{
		return false;
	}
	return fileName.substr(fileName.length() - 4) == ".csv";
}
void BitcoinExchange::applyExchangeRate(std::string& inputFileName)
{
	std::fstream fInput(inputFileName.c_str());
	if (fInput.is_open())
	{
		std::string str;
		std::string target = "|";
		if (getline(fInput ,str))
		{
			if (str != "date | value")
				throw std::invalid_argument("Error: This inputfile is invalid (first string)");
		}
		while (getline(fInput ,str))
		{
			if (str.size() == 0)
				continue;
			std::string	date;
			float		value;

			try
			{
				std::pair<std::string, float> pair = split(str, target);

				date = pair.first;
				value = pair.second;

				checkToInvalidDate(date);
				checkToInvalidValue(value);
				printAllPrice(pair);
			}
			catch (std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		fInput.close();
	}
	else
	{
		throw std::invalid_argument("Error: This inputfile is can't open");
	}
}

void BitcoinExchange::checkToInvalidDate(std::string& date)
{
	std::stringstream	ss(date);
	int		year, month, day;
	char	dash1, dash2;
	std::string	remain;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day) ||
			(dash1 != '-' || dash2 != '-') ||
			year < 2000 || (month < 1 || month > 12) || (day < 1 || day > 31))
	{
		throw std::invalid_argument("Error: InputData has invalid date");
	}
	// del space, check to eof
	if (ss >> remain || remain.size())
	{
		throw std::invalid_argument("Error: InputData has invalid date format");		
	}
	if (month == 2)
	{
		if (isLeapYear(year) == true && day > 29)
			throw std::invalid_argument("Error: InputData Month(2)_");
		else if (isLeapYear(year) == false && day > 28)
			throw std::invalid_argument("Error: InputData Month(2)_");
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		throw std::invalid_argument("Error: InputData Month_day(30)");
	}
}
bool BitcoinExchange::isLeapYear(int year)
{
	if (year%100 ? year%4 : year%400)
		return false;
	return true;
}
void BitcoinExchange::checkToInvalidValue(float value)
{
	if (value < 0 || value > 1000)
		throw std::out_of_range("Error: InputData has invalid value");
}

void BitcoinExchange::printAllPrice(std::pair<std::string, float>& pair)
{
	float exchange_rate = 0;
	std::map<std::string, float>::iterator iter;

	iter  = _data.find(pair.first);
// if not find _data, use the lower date
	if (iter == _data.end())
	{
		iter = _data.lower_bound(pair.first);
		// data.csv보다 input date가 과거일 경우 exchange_rate = 0
		// lower_bound()는 같거나 보다 큰 map을 반환한다.
		if (iter != _data.begin())
		{
			iter--;
			exchange_rate = iter->second;
		}
	}
	else
	{
		exchange_rate = iter->second;
	}
	// else {exit(1);}
	std::cout << pair.first << " => " << pair.second << " = " << pair.second * exchange_rate << std::endl;
}

const std::pair<std::string, float> BitcoinExchange::split(std::string& str, std::string& target)
{
	size_t	pos = str.find(target);
	if (std::string::npos == pos)
	{
		throw std::out_of_range("Error: : This datafile is invalid (target)");
	}
	std::string key = str.substr(0, pos);
	// erase spaces
	key.erase(0, key.find_first_not_of(" "));
	key.erase(key.find_last_not_of(" ") + 1);
	std::string tmp = str.substr(pos + 1);

	float value;
	std::istringstream iss(tmp);
	iss >> value;
	if (!(iss.eof()) || iss.fail())
	{
		throw std::out_of_range("Error: : This datafile is invalid");
	}
	return std::pair<std::string, float>(key, value);
}
