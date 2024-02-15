#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat\t생성자 호출\t(" << this->type << ")" <<std::endl;
	this->type = "cat";
	this->brain = new Brain(this->type);
}
Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat\t복사 생성자 호출" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setideas(copy.brain->getideas(i), i);
}
Cat::~Cat() {
	std::cout << "Cat\t소멸자 호출\t(" << type << ")" << std::endl;
	delete this->brain;
}

void	Cat::makeSound()const {
	std::cout << "🐈 냥냥 📢" << std::endl;
}
const std::string& Cat::getidea(unsigned int idx) {
	std::cout << "> Cat의 getidea\n";
	return this->brain->getideas(idx);
}
void	Cat::changeIdeas() {
	std::cout << "> Cat의 changeIdeas\n";
	this->brain->changeIdeas();
}