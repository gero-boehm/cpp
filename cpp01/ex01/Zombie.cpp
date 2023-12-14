#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie spawned." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " died." << std::endl;
}

void Zombie::setName(const std::string &name)
{
	this->_name = name;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
