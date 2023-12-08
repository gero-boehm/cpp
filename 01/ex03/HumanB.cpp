#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with their fists" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
