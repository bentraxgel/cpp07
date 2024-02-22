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

	Span seok = Span(sp);
	std::cout << "seok : ";
	 seok.getCapacity();
	 std::cout << "change the capacity\n";
	std::cout << "seok : ";
	seok.vectorReserve(100);
	 seok.getCapacity();

	std::cout << "\n add to array\n";
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	seok.addManyNumber(arr, sizeof(arr) / sizeof(*arr));
	for (int i = 0; i < 100; i++)
		std::cout << seok[i] << " ";
	std::cout << "\nshort: " << seok.shortestSpan() << std::endl;
	std::cout << "long: " <<seok.longestSpan() << std::endl;
	std::cout << "[] : " << seok[5] << std::endl;
	std::cout << "[] : " << seok[100];
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
return 0;
}
