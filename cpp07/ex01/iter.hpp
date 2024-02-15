#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename T2>
void	iter(T& arr, int len, T2 func) {
for (int i = 0; i < len; i++)
	func(arr[i]);
}

#endif