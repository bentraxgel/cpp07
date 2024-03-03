#include <iostream>
#include <sstream>

int	main()
{
	const char* av[2];
	av[0] = "test";
	av[1] = " 0 1  2 ";
	std::string str;
	std::stringstream ss(av[1]);

	while (ss >> str)
	{
		std::cout << ss.str() << std::endl;
		std::cout << "str: " << str << std::endl;
	}
	if (!(ss.eof()))
	{
		std::cout << "Error: " << std::endl;
		return -1;
	}

}