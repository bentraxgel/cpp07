#include "Brain.hpp"
#include <sstream>

Brain::Brain() {
	std::cout << "Brain\t기본생성자 호출" << std::endl;
}

Brain::Brain(std::string& think) {
	std::cout << "Brain\tstring생성자 호출" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << i;
		this->ideas[i] = "🧠 이것은 " + think + " 생각이다.[" + ss.str() + "]";
	}
}
Brain::~Brain() {
	std::cout << "Brain\t소멸자 호출" << std::endl;
}

const std::string&	Brain::getideas(unsigned int idx) const {
	return this->ideas[idx];
}
void	Brain::setideas(std::string std, unsigned int idx) {
	this->ideas[idx] = std;
}
void	Brain::changeIdeas() {
	std::cout << "> Brain의 changeIdeas\n";
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << i;
		this->ideas[i] = "✨🧠 이것은 변경된 생각이다.[" + ss.str() + "]";
	}
}