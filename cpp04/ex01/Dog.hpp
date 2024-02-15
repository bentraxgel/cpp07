#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Dog& operator=(const Dog&);
	Brain* brain;
public:
	Dog();
	Dog(const Dog&);
	~Dog();

	void	makeSound() const;
	const std::string& getidea(unsigned int);
	void	changeIdeas();
};

#endif