#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : _name(name) {
	for (unsigned int i = 0; i < _inventory_size; i++)
		_slot[i] = NULL;
}
Character::Character(const Character& copy) {
	for (unsigned int i = 0; i < _inventory_size; i++)
		_slot[i] = copy._slot[i];
}
Character::~Character() {
	for (unsigned int i = 0; i < _inventory_size; i++)
		_slot[i] = NULL;
}

std::string const & Character::getName() const {
	return _name;
}
void Character::equip(AMateria* m) {
	for (unsigned int i = 0; i < _inventory_size; i++) {
		if (_slot[i] == NULL)
			_slot[i] = m;
	}
}
void Character::unequip(int idx) {
	if(0 < idx || static_cast<unsigned int>(idx) > _inventory_size) {
		std::cerr << "Error: Invalid index!\n";
		return;
	}
	_slot[idx] = NULL;
}
void Character::use(int idx, ICharacter& target) {
	if(0 < idx || static_cast<unsigned int>(idx) > _inventory_size) {
		std::cerr << "Error: Invalid index!\n";
		return ;
	}
	_slot[idx]->use(target);
}
