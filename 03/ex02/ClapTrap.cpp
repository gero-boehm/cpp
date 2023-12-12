#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	_name = clapTrap._name;
	_hitPoints = clapTrap._hitPoints;
	_energyPoints = clapTrap._energyPoints;
	_attackDamage = clapTrap._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if(_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack anymore due to being less alive than recommended!" << std::endl;
		return;
	}

	if(_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack anymore due to depleted enery points!" << std::endl;
		return;
	}

	if(_attackDamage == 0)
		std::cout << "ClapTrap " << _name << " tried to attack " << target << " but didn't do any damage because it's a little wussy!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;

	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot take damage anymore due to being less alive than recommended!" << std::endl;
		return;
	}

	if (amount == 0)
	{
		std::cout << "ClapTrap " << _name << " didn't take any damage and and still has " << _hitPoints << " hit points left!" << std::endl;
		return;
	}

	_hitPoints = _hitPoints < amount ? 0 : _hitPoints - amount;

	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and has " << _hitPoints << " hit points left!" << std::endl;

	if(_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired anymore due to being less alive than recommended!" << std::endl;
		return;
	}

	if(_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired anymore due to depleted enery points!" << std::endl;
		return;
	}

	_hitPoints += amount;

	std::cout << "ClapTrap " << _name << " was repaired for " << amount << " points of health and is now at " << _hitPoints << " hit points!" << std::endl;

	_energyPoints--;
}
