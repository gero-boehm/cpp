#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	*this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	if (this == &materiaSource)
		return *this;

	for (int i = 0; i < MAX_MATERIA; i++)
		_materias[i] = materiaSource._materias[i] == NULL ? NULL : materiaSource._materias[i]->clone();

	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
		delete _materias[i];
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_materias[i] == NULL) {
			_materias[i] = materia;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_materias[i] != NULL && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}

	return NULL;
}
