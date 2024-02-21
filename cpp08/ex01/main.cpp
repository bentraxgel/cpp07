#include <vector>
#include "Span.hpp"

int main()
{
try
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "short: " << sp.shortestSpan() << std::endl;
	std::cout << "long: " << sp.longestSpan() << std::endl;

	Span seok = Span(100);
	std::cout << "seok : ";
	 seok.getcapacity();
	seok.addManyNumber(10);
	for (int i = 0; i < 10; i++)
		std::cout << seok[i] << " ";
	std::cout << "\nshort: " << seok.shortestSpan() << std::endl;
	std::cout << "long: " <<seok.longestSpan() << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
return 0;
}
