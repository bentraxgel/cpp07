#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
	for (unsigned int i = 0; i < _slot_size; i++)
		_slot[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& copy) {
	for (unsigned int i = 0; i < _slot_size; i++)
		_slot[i] = copy._slot[i];
}
MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	if (this != &copy) {
		for (unsigned int i = 0; i < _slot_size; i++)
			_slot[i] = copy._slot[i];
	}
	return *this;
}
MateriaSource::~MateriaSource() {
	for (unsigned int i = 0; i < _slot_size; i++) {
		if (_slot[i])
			delete _slot[i];
	}
}

void	MateriaSource::learnMateria(AMateria* materia) {
	for (unsigned int i = 0; i < _slot_size; i++) {
		if (_slot[i] == NULL){
			_slot[i] = materia;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (unsigned int i = 0; i < _slot_size; i++) {
		if (_slot[i] && type == _slot[i]->getType())
			return _slot[i]->clone();
	}
	return NULL;
}
