#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector> 
#include <deque>
// #include <iomanip> < DRBUG
#include <cmath>
#include <sstream>
#include <exception>
#include <ctime>

struct Node
{
public:
	Node*	left;
	Node*	right;
	int		value;
	
	// DEBUG
	int		level;
};

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	std::vector<int>	_vec;
	std::deque<int>		_dq;
public:
	PmergeMe(char**);
	~PmergeMe();
	std::vector<int>& getVector();
	std::deque<int>& getDeque();

	void	makeVector(char**);
	void	makeDeque();

	void	printToVector(std::string str);

	template <typename T>
	void Pmerge(T src);
	void Pmerge(std::vector<int>& vec);
	void Pmerge(std::deque<int>& vec);

	void PmergeImpl(std::vector<int>& source);
	void PmergeImpl(std::deque<int>& source);

	class InvalidInput : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "🚫 Error 🚫";
		}
	};
};

// inline const char* PmergeMe::InvalidInput::what() const throw()
// {
// 	return "🚫 Error 🚫";
// }

#endif