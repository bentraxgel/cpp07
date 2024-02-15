#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	Dog& operator=(const Dog&);
public:
	Dog();
	Dog(const Dog&);
	~Dog();

	void	makeSound() const;
};

#endif