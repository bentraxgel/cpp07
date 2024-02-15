#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("(empty)") {
	std::cout << "WrongAnimal\t생성자 호출\t(" << type << ")" <<std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "WrongAnimal\t복사 생성자 호출" << std::endl;
	this->type = copy.type;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal\t소멸자 호출\t(" << type << ")" << std::endl;
}

const std::string&	WrongAnimal::getType() const {
	return (this->type);
}
void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimalSound 📢" << std::endl;
}