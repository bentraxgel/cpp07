#include <iostream>

class ICharacter;

class AMateria
{
protected:
//	[...]
public:
	AMateria(std::string const & type); //Materia typename (lowercase)
//	[...]
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

void AMateria::use(ICharacter& target) {

}