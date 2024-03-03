#include <sstream>
#include <iostream>
#include <vector>

struct node
{
	int num;
	std::string value;
};


int	main()
{
	std::vector<node> vec;


for (int i = 0; i < 15; i++)
{
	node a;
	a.num = i + 1;
	a.value = i + '0';
	
	vec.push_back(a);
}

std::vector<node>::iterator iter;
for (iter = vec.begin(); iter != vec.end(); iter++)
{
	std::cout << iter->num << ": " << iter->value << std::endl;
}

}