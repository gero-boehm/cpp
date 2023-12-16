#include "Floor.hpp"
#include <iostream>

Floor::Floor(void): _capacity(0)
{
	for (int i = 0; i < MAX_CAPACITY; i++)
		_materias[i] = NULL;
}

Floor::Floor(const Floor &floor)
{
	*this = floor;
}

Floor &Floor::operator=(const Floor &floor)
{
	if (this == &floor)
		return *this;

	_capacity = floor._capacity;

	for (int i = 0; i < _capacity; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;

		if (floor._materias[i] != NULL)
			_materias[i] = floor._materias[i]->clone();
	}

	return *this;
}

Floor::~Floor()
{
	for (int i = 0; i < _capacity; i++)
		delete _materias[i];
}

void Floor::addMateria(AMateria *materia)
{
	if (_capacity == MAX_CAPACITY)
		return;

	_materias[_capacity] = materia;
	_capacity++;
}

Floor &Floor::getInstance(void)
{
	static Floor instance;
	return instance;
}
