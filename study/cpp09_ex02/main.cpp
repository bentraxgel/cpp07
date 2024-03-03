#include <vector>
#include <deque>
#include <ctime>

#include "PmergeMe.hpp"

template <typename T>
void	validateForPrint(std::string, T);

int	main(int argc, char* argv[])
{
	// if ( argc == 1)
	// {
	// 	std::cerr << "Error: invalid input" << std::endl;
	// 	return -1;
	// }

	// Parsing argument
	// TOOD: Implement it.
	std::vector<int> arg;
(void)argc;
(void)argv;
	// Vector Performance Test
	{
		std::vector<int> vec;

		vec.push_back(3);
		vec.push_back(2);
		vec.push_back(1);
		vec.push_back(4);
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(5);
		// time_t start = time(NULL);
		validateForPrint("Before", vec);
		Pmerge(vec);
		validateForPrint("After", vec);

	std::deque<int> dq;
	dq.push_back(9);
	dq.push_back(3);
	dq.push_back(8);
	dq.push_back(7);
	dq.push_back(12);
	dq.push_back(5);
	dq.push_back(6);
	dq.push_back(4);
	dq.push_back(1);
	dq.push_back(10);
	dq.push_back(2);
	dq.push_back(13);
	validateForPrint("Before", dq);
	Pmerge(dq);
	validateForPrint("After", dq);

		// time_t end = time(NULL);
		
		// print test time (end - start)
		// TODO: Implement it.
	}

	//  Dequeue Performance Test
	{
		// TODO: Impelement it.
	}

	// Print Test Result
	// TOOD:
	
	return 0;
}

template <typename T>
void	validateForPrint(std::string str, T container)
{
	std::cout << str << ":\t";
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}
