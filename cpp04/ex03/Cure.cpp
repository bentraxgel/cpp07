#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure& copy) : AMateria(copy) {}
Cure& Cure::operator=(const Cure& copy) {
	if (this != &copy)
		_type = copy._type;
	return *this;
}
Cure::~Cure() {}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "Cure: \"* heals " << target.getName() << "’s wounds *\"\n";
}
