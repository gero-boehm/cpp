#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this == &animal)
		return *this;
	_type = animal._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}


const std::string &Animal::getType(void) const
{
	return _type;
}

void Animal::makeSound(void) const
{
	std::cout << "The " << _type << " says bleurgh!" << std::endl;
}
