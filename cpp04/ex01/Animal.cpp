#include "Animal.hpp"

Animal::Animal() : type("(empty)") {
	std::cout << "Animal\t생성자 호출\t(" << type << ")" <<std::endl;
}
Animal::Animal(const Animal& copy) {
	std::cout << "Animal\t복사 생성자 호출" << std::endl;
	this->type = copy.type;
}
Animal::~Animal() {
	std::cout << "Animal\t소멸자 호출\t(" << type << ")" << std::endl;
}

const std::string&	Animal::getType() const {
	return (this->type);
}
void	Animal::makeSound() const {
	std::cout << "AnimalSound 📢" << std::endl;
}