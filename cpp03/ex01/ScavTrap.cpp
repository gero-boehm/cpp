#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	_name = scavTrap._name;
	_hitPoints = scavTrap._hitPoints;
	_energyPoints = scavTrap._energyPoints;
	_attackDamage = scavTrap._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if(_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack anymore due to being less alive than recommended!" << std::endl;
		return;
	}

	if(_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack anymore due to depleted enery points!" << std::endl;
		return;
	}

	if(_attackDamage == 0)
		std::cout << "ScavTrap " << _name << " tried to attack " << target << " but didn't do any damage because it's a little wussy!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;

	_energyPoints--;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has entered in gate keeper mode!" << std::endl;
}
