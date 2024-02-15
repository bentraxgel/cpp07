#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure&);
	Cure& operator=(const Cure&);
	~Cure();
	AMateria* clone() const;
	void use(ICharacter& target);
};
