#include <vector>
#include <iostream>

int	main() {
std::vector<char> vec;

vec.push_back('a');


std::vector<char>::iterator o = vec.begin();
std::cout << "begin: " << *o << "\n";
o = vec.end();
std::cout << "end: " << *o << "\n";
// std::cout << "size: " << sizeof(o);
std::cout << "size: " << sizeof(*o);

}