#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string	ideas[100];
	Brain& operator=(const Brain&);
	Brain(const Brain&);
public:
	Brain();
	Brain(std::string&);
	~Brain();
	const std::string&	getideas(unsigned int) const;
	void	setideas(std::string std, unsigned int idx);
	void	changeIdeas();
};

#endif