#include <iostream>
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"

int	main() {
	ICharacter* a = new Character("name");
	ICharacter* b = new Character("tmp");
	// a->use(0, *b);
	(void)a;
	(void)b;

}
