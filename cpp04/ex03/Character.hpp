#pragma once

#include <iostream>
#include "ICharacter.hpp"
class AMateria;

class Character : public ICharacter
{
public:
	Character(std::string);
	Character(const Character&);
	Character& operator= (const Character&);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string	_name;
	static const unsigned int	_inventory_size = 4;
	AMateria*	_slot[_inventory_size];

	Character();
};
