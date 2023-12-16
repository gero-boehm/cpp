#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat), _brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &cat)
		return *this;
	_type = cat._type;
	if(_brain != NULL)
		delete _brain;
	_brain = new Brain(*cat._brain);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound(void) const
{
	std::cout << "The " << _type << " says meow!" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return _brain;
}
