#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : _name(name) {
	for (unsigned int i = 0; i < _inventory_size; i++)
		_inven[i] = NULL;
}
Character::Character(const Character& copy) {
	for (unsigned int i = 0; i < _inventory_size; i++)
		_inven[i] = copy._inven[i]->clone();
}
Character& Character::operator= (const Character& copy) {
	if (this != &copy) {
		for (unsigned int i = 0; i < _inventory_size; i++)
			_inven[i] = copy._inven[i]->clone();
	}
	return *this;
}
Character::~Character() {
	for (unsigned int i = 0; i < _inventory_size; i++){
		if (_inven[i])
			delete _inven[i];
		_inven[i] = NULL;
	}
}

std::string const & Character::getName() const {
	return _name;
}
void Character::equip(AMateria* m) {
	for (unsigned int i = 0; i < _inventory_size; i++) {
		if (_inven[i] == NULL){
			_inven[i] = m;
			return ;
		}
	}
}
void Character::unequip(int idx) {
	if (idx < 0 || static_cast<unsigned int>(idx) >= _inventory_size) {
		std::cerr << "Error: Invalid index!\n";
		return;
	}
	_inven[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || static_cast<unsigned int>(idx) >= _inventory_size) {
		std::cerr << "Error: Invalid index!\n";
		return ;
	}
	_inven[idx]->use(target);
}
