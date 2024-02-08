#include "iter.hpp"

template <typename T>
void	print(T& call) {
std::cout << call << " ";
}

int	main() {
std::cout << "* * * int array * * *\n";
	int iarr[5] = {10, 20, 30, 40, 50};
	iter(iarr, sizeof(iarr) / sizeof(*iarr), print<int>);

std::cout << "\n\n* * * float array * * *\n";
	float farr[5] = {1.01f, 2.01f, 3.01f, 4.01f, 5.01f};
	iter(farr, sizeof(farr) / sizeof(*farr), print<float>);

std::cout << "\n\n* * * string array * * *\n";
	std::string sarr[5] = {"hello", "my", "name", "is", "seok"};
	iter(sarr, sizeof(sarr) / sizeof(*sarr), print<std::string>);
}