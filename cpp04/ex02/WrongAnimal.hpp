#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
private:
	WrongAnimal& operator=(const WrongAnimal&);
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal&);
	~WrongAnimal();

	const std::string&	getType() const;
	void		makeSound() const;
};

#endif