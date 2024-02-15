#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < _inventory_size; i++)
		_slot[i] = NULL;
}

Character::Character(const Character& copy) {
	
}