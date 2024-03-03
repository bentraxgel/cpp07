#include <iostream>
#include <sstream>

class test
{
private:
	/* data */
public:
	test(/* args */);
	~test();
	void	printav(int ac, char** av);

	class testerr : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

const char* test::testerr::what() const throw()
{
	return "ERROR!";
}

test::test(/* args */)
{
}

test::~test()
{
}


void	test::printav(int ac, char** av)
{
	int arr[10];

	if (ac == 1)
	{
		throw testerr();
	}
	for (int i = 1; av[i]; i++)
	{
		// int num;
		std::istringstream ss(av[i]);
		int num;
		if (!(ss >> num) || num <= 0)
		// ss >> num;
		// if (ss.fail() == true || num <= 0)
		{
			std::cout << "num: " << num <<std::endl;
			throw testerr();
		}
		arr[i - 1] = num;
	}
	std::cout << "\n*******************\n";
	for (int i = 0; i < ac - 1; i++)
		std::cout << arr[i]	<< std::endl;
}


int	main(int ac, char* av[])
{
	test t;
	try
	{
	t.printav(ac, av);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
