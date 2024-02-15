#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type( "empty" ) {}
AMateria::AMateria(std::string const & type) 
		: _type(type) {}
AMateria::AMateria(const AMateria& copy) 
		: _type(copy._type) {}
AMateria& AMateria::operator= (const AMateria& copy) {
	if (this != &copy)
		_type = copy._type;
	return *this;
}
AMateria::~AMateria() {};

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Error: \"* Nothing works for " << target.getName() << " \"\n";
}