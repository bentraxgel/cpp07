#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
private:
	unsigned int	_N;
	Span();
public:
	Span(unsigned int);
	Span(&Span);
	~Span();
	void	addNumber();
};

Span::Span(unsigned int n) : _N(n)
{
}

Span::~Span()
{
}


#endif