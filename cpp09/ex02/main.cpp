#include <vector>
#include <deque>
#include <ctime>

#include "PmergeMe.hpp"

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

	// Vector Performance Test
	{
		std::vector<int> vec = {3, 2, 1, 4, 5, 6, 5};

		time_t start = time(NULL);
		Pmerge(vec);
		time_t end = time(NULL);
		
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
