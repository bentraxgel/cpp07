#include <vector>
#include <iostream>
#include "easyfind.hpp"

int	main() {
std::vector<int> vec;
std::vector<int>::iterator iter;

for (int i = 0; i < 5; i++)
	vec.push_back(i + 10);
std::cout << "vec size: " << vec.size() << "\n";

try
{
std::cout << "\n=== find할 수 있는 값. ===\n";
iter = easyfind(vec, 11);
std::cout << "iter: " << *iter << "\n";
std::cout << "\n=== find할 수 있는 값. ===\n";
iter = easyfind(vec, 100);
std::cout << "iter: " << *iter << "\n";
}
catch(const std::exception& e)
{
	std::cerr << "🚫 Not Found" << '\n';
}


}