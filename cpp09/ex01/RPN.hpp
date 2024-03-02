#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>

class RPN
{
private:
	RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	std::stack<int> _stack;
public:
	RPN(char**);
	~RPN();

	bool isOperationToken(std::string&);
	bool isNumber(std::string&);

	void	operate(std::string&);

	class InvalidInput : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "🚫 Error: Invalid input 🚫";
		}
	};
	class failedPoint : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "🚫 Error: Fail to transform 🚫";
		}
	};
};

#endif