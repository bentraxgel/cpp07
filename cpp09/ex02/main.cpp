#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	if ( argc == 1)
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
