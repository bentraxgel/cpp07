#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

// void	leak() {system("leaks -q Interface");}

int main()
{
// atexit(leak);

IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* me = new Character("me");

AMateria* tmp;
AMateria* tmp1;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp1 = src->createMateria("cure");
me->equip(tmp1);

ICharacter* bob = new Character("bob");

me->use(0, *bob);
me->use(1, *bob);

/* add to unequip() */
me->unequip(0);
me->unequip(1);
delete tmp1;
delete tmp;

delete bob;
delete me;
delete src;

// while (1) {}
// system("leaks Interface");

return 0;
}
