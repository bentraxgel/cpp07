#include <iostream>
#include <iterator>
#include <vector>

int	main() {
	std::vector<int> v;
	// v.reserve(10);
	// std::cout << *v.begin() << std::endl;
	std::vector<int>::iterator iter;

v.push_back(10);
for (size_t i = 0; i < v.size(); i++)
	v[i] = 1;
std::cout << *v.begin() << "\t";

	// for (iter = begin(v); iter != end(v); iter++) {
	// 	v.push_back(5);
	// 	std::cout << "iter: ";
	// 	std::cout << *iter << "\n";
	// }

	// std::cout << "TEST";
	// for (iter = v.begin(); iter != v.end(); iter++) {
	// 	std::cout << "before: " << *iter << "\n";
	// 	*iter = 100;
	// 	std::cout << "after: " << *iter << "\n";
	// }
}

