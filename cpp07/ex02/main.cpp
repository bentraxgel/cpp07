#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
// int	main() {
// 	Array<int> a(5);
// 	for (int i = 0; i < 5; i++) {
// 		std::cout << "before: " << a[i] << "\n";
// 		a[i] = i + 10;
// 		std::cout << "after: " << a[i] << "\n";
// 	}

// std::cout << "\n\n* * * * * * *\n";
// 	Array<int> b(a);
// 	for (int i = 0; i < 5; i++) {
// 		b[i] = 100;
// 		std::cout << a[i] << " : " << b[i] <<"\n";
// 	}

// std::cout << "\n\n* * * * * * *\n";
// a = b;
// b[0] = 0;
// std::cout << "b[0]: " << b[0] << "\n";
// for (int i = 0; i < 5; i++)
// 	std::cout << a[i] << " ";
// }