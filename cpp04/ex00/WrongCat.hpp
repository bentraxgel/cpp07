#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	WrongCat& operator=(const WrongCat&);
public:
	WrongCat();
	WrongCat(const WrongCat&);
	~WrongCat();

	void	makeSound() const;
};

#endif