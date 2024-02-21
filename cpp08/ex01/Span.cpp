#include "Span.hpp"
#include <algorithm>
#include <cstdlib>

Span::Span(unsigned int n)\
 : _capacity(n)
{}
Span::Span(const Span& rhs)
 : _capacity(rhs._capacity)
 , _vector(rhs._vector)
{}
Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_capacity = rhs._capacity;
	}
	return *this;
}
Span::~Span() {}
int Span::operator[](const unsigned int idx)
{
	if (idx >= _capacity)
		throw invalid();
	return _vector[idx];
}

void	Span::addNumber(int n)
{
	if (_vector.size() >= _capacity)
		throw invalid();
	_vector.push_back(n);
}

void	Span::addManyNumber(unsigned int n)
{
	unsigned int inputSize = _vector.size() + n;
	std::cout << "size: " << inputSize << std::endl;
	if (inputSize >= _capacity) {

		throw invalid();
	}
	std::cout << "TEST";
	std::srand(time(NULL));
	for (unsigned int i = _vector.size(); i < inputSize; i++) {
		std::cout << "vector[" << i << "]: "<< _vector[i] << std::endl;
		_vector[i] = rand() % 1000;
	}
}
std::vector<int> makeVectorNearDiff(std::vector<int> target)
{
	std::vector<int>	result;
	result.reserve(target.size() - 1);
	for (std::vector<int>::iterator	it = target.begin(); it + 1 != target.end(); ++it)
	{
		int a = *it;
		int b = *(it + 1);
		result.push_back(abs(a - b));
	}
	return result;
}

int		Span::shortestSpan() {
	std::vector<int> diffVec = makeVectorNearDiff(_vector);
	return *(std::min_element(diffVec.begin(), diffVec.end()));
}
int		Span::longestSpan() {
	std::vector<int> diffVec = makeVectorNearDiff(_vector);
	return *(std::max_element(diffVec.begin(), diffVec.end()));
}

const char* Span::invalid::what() const throw()
{
	return "Error: Invalid";
}
