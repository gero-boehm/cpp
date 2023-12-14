#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &dog)
		return *this;
	_type = dog._type;
	_brain = new Brain(*dog._brain);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound(void) const
{
	std::cout << "The " << _type << " says woof!" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return _brain;
}
