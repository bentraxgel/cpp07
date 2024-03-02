#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	BitcoinExchange	btc;

	if (argc != 2)
	{
		std::cerr<< "Error: could not open file." << std::endl;
		return -1;
	}
	std::string	dataFileName = "data.csv";
	std::string	inputFileName = argv[1];
	if (btc.isCSVFile(inputFileName) == false)
	{
		std::cerr << "Error: This file is not .csv file" << std::endl;
		return -1;
	}

try
{
	btc.makeDataMap(dataFileName);
	btc.applyExchangeRate(inputFileName);
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}

}
