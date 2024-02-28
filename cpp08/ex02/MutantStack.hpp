#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack& rhs)
	{
		*this = rhs;
	}
	MutantStack& operator=(const MutantStack& rhs)
	{
		std::stack<T>::operator=(rhs);
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator			iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

	iterator begin()
	{
		return std::stack<T>::c.begin();
	}
	iterator end()
	{
		return std::stack<T>::c.end();
	}
	reverse_iterator reverse_begin()
	{
		return std::stack<T>::c.rbegin();
	}
	reverse_iterator reverse_end()
	{
		return std::stack<T>::c.rend();
	}
};

#endif