#pragma once
#ifndef MATERIASOUCE_HPP
#define MATERIASOUCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource&);
	MateriaSource& operator=(const MateriaSource&);
	~MateriaSource();
	void	learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
private:
	static const unsigned int	_slot_size = 4;
	AMateria*	_slot[_slot_size];
};

#endif