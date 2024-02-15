#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "cat";
	std::cout << "WrongCat\t생성자 호출\t(" << this->type << ")" <<std::endl;
}
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat\t복사 생성자 호출" << std::endl;
	this->type = copy.type;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat\t소멸자 호출\t(" << type << ")" << std::endl;
}

void	WrongCat::makeSound()const {
	std::cout << "🐈 냥냥 📢" << std::endl;
}