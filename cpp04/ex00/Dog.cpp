#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog\t생성자 호출\t(" << type << ")" <<std::endl;
	this->type = "Dog";
}
Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog\t복사 생성자 호출" << std::endl;
	this->type = copy.type;
}
Dog::~Dog() {
	std::cout << "Dog\t소멸자 호출\t(" << type << ")" << std::endl;
}

void	Dog::makeSound()const {
	std::cout << "🐕 멍멍 📢" << std::endl;
}