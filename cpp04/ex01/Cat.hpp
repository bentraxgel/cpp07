#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Cat& operator=(const Cat&);
	Brain* brain;
public:
	Cat();
	Cat(const Cat&);
	~Cat();
	void	makeSound() const;
	const std::string& getidea(unsigned int);
	void	changeIdeas();
};

#endif