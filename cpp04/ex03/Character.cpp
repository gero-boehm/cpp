#include "AMateria.hpp"
#include "Character.hpp"
#include "Floor.hpp"

Character::Character(void): _name("undefined")
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name): _name(name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &character)
{
	*this = character;
}

Character &Character::operator=(const Character &character)
{
	if (this == &character)
		return *this;

	_name = character._name;

	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;

		if (character._inventory[i] != NULL)
			_inventory[i] = character._inventory[i]->clone();
	}

	return *this;
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		delete _inventory[i];
}

const std::string &Character::getName(void) const
{
	return _name;
}

void Character::equip(AMateria *materia)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (_inventory[i] == NULL) {
			_inventory[i] = materia;
			return;
		}
	}
}

void Character::unequip(int index)
{
	if (index < 0 || index >= INVENTORY_SIZE)
		return;

	Floor::getInstance().addMateria(_inventory[index]);

	_inventory[index] = NULL;
}

void Character::use(int index, ICharacter &target)
{
	if (index < 0 || index >= INVENTORY_SIZE || _inventory[index] == NULL)
		return;

	_inventory[index]->use(target);
}
