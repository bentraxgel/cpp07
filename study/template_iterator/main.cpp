#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main() {
std::vector<int> vec;
std::vector<int> v2;

vec.push_back(22);
v2.push_back(202);

std::vector<int>::iterator o = vec.begin();
std::cout << "begin: " << *o << "\n";
o = vec.end();
std::cout << "end: " << *o << "\n";
std::cout << "size: " << sizeof(*o);

std::cout << "\n* * *  * easy\n\n";
try
{
o = easyfind(v2, 'g');
std::cout << "try: " << *o;
	
}
catch(const std::exception& e)
{
	std::cerr << e.what() << " Not Found" << '\n';
}


}