#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid Input" << std::endl;
		return -1;
	}
	try
	{
		RPN	rpn(argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}