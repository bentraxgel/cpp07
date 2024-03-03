#pragma once

#include <iostream>
#include <vector> 
#include <deque>
#include <iomanip>
#include <cmath>

template <typename T>
void Pmerge(T src);
void Pmerge(std::vector<int>& vec);
void Pmerge(std::deque<int>& vec);

void PmergeImpl(std::vector<int>& source);
void PmergeImpl(std::deque<int>& source);


struct Node
{
public:
	Node*	left;
	Node*	right;
	int		value;
	
	// DEBUG
	int		level;
};
