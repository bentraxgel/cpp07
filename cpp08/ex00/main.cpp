#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main() {
std::cout << "\n* * * * * * * vector * * * * * * *\n";

std::vector<int> vec;
std::vector<int>::iterator iter;

for (int i = 0; i < 5; i++)
	vec.push_back(i + 10);
std::cout << "vec size: " << vec.size() << "\n";
for (int i = 0; i < 5; i++)
	std::cout << "vec[" << i << "]: " << vec[i] << "\n";

try
{
std::cout << "\n=== find할 수 있는 값. ===\n";
iter = easyfind(vec, 11);
std::cout << "iter: " << *iter << "\n";
std::cout << "\n=== find할 수 없는 값. ===\n";
iter = easyfind(vec, 100);
std::cout << "iter: " << *iter << "\n";
}
catch(const std::exception& e)
{
	std::cerr << "🚫 vertor Not Found" << '\n';
}

std::cout << "\n* * * * * * * list * * * * * * *\n";
 std::list<int> lst;
 for (int i = 0; i < 5; i++)
	lst.push_back(i + 10);
 
	lst.push_front(112);
	lst.push_back(119);
std::cout << "lst size: " << lst.size() << "\n";
std::list<int>::iterator it;
for (it = lst.begin(); it != lst.end(); it++)
	std::cout << *it << " ";
try 
{
std::cout << "\n\n=== find할 수 있는 값. ===\n";
it = easyfind(lst, 119);
std::cout << "list Found iter: " << *it << "\n";
std::cout << "\n=== find할 수 없는 값. ===\n";
it = easyfind(lst, 100);
std::cout << "list Found iter: " << *it << "\n";

} catch (std::exception e)
{
	std::cout << "🚫 list Not Found\n";
}

}