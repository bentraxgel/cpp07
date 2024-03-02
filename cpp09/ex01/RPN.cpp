#include "RPN.hpp"

RPN::RPN(char** argv)
{
	std::string			token;
	std::stringstream	ss(argv[1]);
	while (ss >> token)
	{
		if (isOperationToken(token))
		{
			operate(token);
		}
		else if (isNumber(token))
		{
		}
		else
		{
			throw InvalidInput();
		}
	}
	if (!(ss.eof()))
	{
		throw InvalidInput();
	}
	if (_stack.size() != 1)
	{
		throw InvalidInput();
	}
	// finish RPN. print to result
	std::cout << _stack.top() << std::endl;

}
RPN::~RPN() {}

bool	RPN::isOperationToken(std::string& token)
{
	if (token == "+" || token == "-" || token == "/" || token == "*")
		return true;
	return false;
}
bool	RPN::isNumber(std::string& token)
{
	std::istringstream	iss(token);
	std::string			str;
	if (!(iss >> str) || str.length() > 1)
	{
		throw failedPoint();
	}
	if (isdigit(str[0]))
	{
		_stack.push(str[0] - '0');
		return true;
	}
	return false;
}

void	RPN::operate(std::string& token)
{
	if (_stack.size() < 2)
	{
		throw InvalidInput();
	}
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();

	std::istringstream iss(token);
	char	ch;
	if (!(iss >> ch))
	{
		throw failedPoint();
	}

	switch (ch)
	{
	case '+':
		_stack.push(b + a);
		break;
	case '-':
		_stack.push(b - a);
		break;
	case '/':
		if (a == 0)
		{
			throw InvalidInput();
		}
		_stack.push(b / a);
		break;
	case '*':
		_stack.push(b * a);
		break;
	default:
		break;
	}
}