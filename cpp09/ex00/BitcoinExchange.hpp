#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>

/** @brief The bitcoin database that processing query.
 * 
 *  @warning Input data and arguments are must be valid.
 * 			 Input data format must be YYYY-MM-DD | [value]
*/
class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;

	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);
public:
	BitcoinExchange();
	~BitcoinExchange();

	// Source data file must be valid.
	void makeDataMap(std::string&);

	bool isCSVFile(std::string);

	void applyExchangeRate(std::string&);
	void checkToInvalidDate(std::string&);
	void checkToInvalidValue(float);
	bool isLeapYear(int);
	void printAllPrice(std::pair<std::string, float>&);

	const std::pair<std::string, float> split(std::string&, std::string&);


};



#endif