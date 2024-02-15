#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	Cat& operator=(const Cat&);
public:
	Cat();
	Cat(const Cat&);
	~Cat();

	void	makeSound() const;
};

#endif