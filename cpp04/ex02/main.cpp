#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
Animal* animal[4];
for (int i = 0; i < 4; i++){
	if (i % 2)
		animal[i] = new Cat();
	else
		animal[i] = new Dog();
	animal[i]->makeSound();
}
for (int i = 0; i < 4; i++)
	delete animal[i];


std::cout << "=========================================" << std::endl;
Cat cat;
Cat copy(cat);
std::cout << cat.getidea(10) << std::endl;
std::cout << copy.getidea(10) << std::endl;
cat.changeIdeas();
std::cout << cat.getidea(10) << std::endl;
std::cout << copy.getidea(10) << std::endl;

return 0;
}