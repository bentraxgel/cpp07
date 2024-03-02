#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	if (argc == 1 || argc > 10000000)
	{
		std::cout << "Error: invalid input" << std::endl;
		return -1;
	}
	// Parsing argument
	try
	{
		PmergeMe	pm(argv);
		clock_t		startTime;
		clock_t		finishTime;
		
	// std::vector<int>
		pm.printToVector("Before");

		startTime = clock();
		pm.Pmerge(pm.getVector());
		finishTime = clock();

		double vecTime = static_cast<double>(finishTime - startTime);

		pm.printToVector("After");

	 	// Flush the old cache with write into new memory locations,
		// and using random access to avoding hardware cache prefetcher's predictor unit.
		{
			enum { CACHE_LINE_SIZE = 64 };
			enum { L3_SIZE = 1024 * 1024 * 64 }; //< 64mb
			char* buf = new char[L3_SIZE];
			for (int i = 0; i < L3_SIZE; i++)
				buf[rand() % (L3_SIZE / CACHE_LINE_SIZE)] = 0;
		}

	// std::deque<int>
		startTime = clock();
		pm.Pmerge(pm.getDeque());
		finishTime = clock();

		double dqTime = static_cast<double>(finishTime - startTime);

	// print to two containers sorting time
		std::cout << "Time to process a range of "
				<< argc - 1 << " elements with std::vector\t: " << vecTime / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
		std::cout << "Time to process a range of "
				<< argc - 1 << " elements with std::deque\t: " << dqTime / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

		return 0;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
}
