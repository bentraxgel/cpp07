#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice&);
	Ice& operator=(const Ice&);
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
// private:
};

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& copy) : AMateria(copy) {}
Ice& Ice::operator=(const Ice& copy) {
	if (this != &copy)
		_type = copy._type;
	return *this;
}
Ice::~Ice() {}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"\n";
}
// 		std::cout << "Cure: \"* heals " << target.getName() << "’s wounds *\"\n";
