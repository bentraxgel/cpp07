#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "🐶: " << j->getType() << ":\t";
	j->makeSound();
	std::cout << "🐱: " << i->getType() << ":\t";
	i->makeSound();
	std::cout << "  : " << meta->getType() << ":\t";
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	// return 0;
	}
	{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << "🐱: " << i->getType() << ":\t";
	i->makeSound();
	std::cout << "  : " << meta->getType() << ":\t";
	meta->makeSound();

	delete meta;
	delete i;
	return 0;
	}
}