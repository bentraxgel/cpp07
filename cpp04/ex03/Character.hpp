#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(std::string);
	Character(const Character&);
	Character& operator= (const Character&);
	~Character();


private:
	std::string	_name;
	static const unsigned int	_inventory_size = 4;
	AMateria*	_slot[_inventory_size];
	Character();
};

/*
[ ] 궁금증: '_inventory_size'
	class에 저장하는게 나을가 매크로 선언하는게 나을까?
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;

*/

#endif