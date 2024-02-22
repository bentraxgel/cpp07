#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>

class Span
{
private:
	unsigned int	_capacity;
	std::vector<int> _vector;
	Span();
public:
	Span(unsigned int);
	Span(const Span&);
	Span& operator=(const Span& rhs);
	~Span();
	int operator[](const unsigned int idx);
	void	vectorReserve(int size);

	void	addNumber(int n);
	void	addManyNumber(int* arr, unsigned int n);
	int		shortestSpan();
	int		longestSpan();

	class invalid : public std::exception
	{
		public:
			const char* what() const throw();
	};
	void	getCapacity()
	{
		std::cout << "_capacity: " << _capacity << std::endl;
	}
};


#endif