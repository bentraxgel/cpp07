#include <iostream>
#include <algorithm>
#include <vector>

int	main() {
	std::vector<int> v;
	std::vector<int> aaaa = {1, 2, 3};
	aaaa.push_back(100);
	std::cout << "vector size: " << v.size() << "\n";
	std::cout << "vector size: " << aaaa.size() << "\n";
}