#include <iostream>
#include "Span.hpp"

int	main() {
	Span s(5);
try
{
	for (int i = 0; i < 5; i++) {
		s.addNumber(i + 10);
		std::cout << s[i] << " ";
	}

	Span c(s);
	for (int i = 0; i < 5; i++) {
		std::cout << c[i] << " ";
	}

	c.addManyNumber(3);
	for (int i = 0; i < 3; i++)
		std::cout << c[i] << " ";
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}

}
