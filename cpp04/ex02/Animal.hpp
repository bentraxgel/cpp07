#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
private:
	Animal& operator=(const Animal&);
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal&);
	virtual ~Animal();
	const std::string&	getType() const;
	virtual void		makeSound() const = 0;
};

#endif