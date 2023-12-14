#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " spawned." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " died." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
