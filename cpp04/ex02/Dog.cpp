#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog\t생성자 호출\t(" << type << ")" <<std::endl;
	this->type = "Dog";
	this->brain = new Brain(this->type);
}
Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog\t복사 생성자 호출" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setideas(copy.brain->getideas(i), i);
}
Dog::~Dog() {
	std::cout << "Dog\t소멸자 호출\t(" << type << ")" << std::endl;
	delete this->brain;
}

void	Dog::makeSound()const {
	std::cout << "🐕 멍멍 📢" << std::endl;
}
const std::string& Dog::getidea(unsigned int idx) {
	std::cout << "> Dog의 getidea\n";
	return this->brain->getideas(idx);
}
void	Dog::changeIdeas() {
	std::cout << "> Dog의 changeIdeas\n";
	this->brain->changeIdeas();
}