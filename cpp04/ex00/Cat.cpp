#include "Cat.hpp"

Cat::Cat() {
	this->type = "cat";
	std::cout << "Cat\t생성자 호출\t(" << this->type << ")" <<std::endl;
}
Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat\t복사 생성자 호출" << std::endl;
	this->type = copy.type;
}
Cat::~Cat() {
	std::cout << "Cat\t소멸자 호출\t(" << type << ")" << std::endl;
}

void	Cat::makeSound()const {
	std::cout << "🐈 냥냥 📢" << std::endl;
}