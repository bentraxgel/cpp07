#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& contaior, int n) {
	typename T::iterator iter;
	iter = std::find(contaior.begin(), contaior.end(), n);
	if (iter == contaior.end())
		throw std::exception();
	return iter;
}
#endif