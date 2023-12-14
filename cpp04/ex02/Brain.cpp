#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignment operator called" << std::endl;

	if (this == &brain)
		return *this;

	for (int i = 0; i < MAX_IDEAS; i++)
		this->ideas[i] = brain.ideas[i];

	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

