#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define MAX_MATERIA 4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_materias[MAX_MATERIA];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &materiaSource);
		MateriaSource &operator=(const MateriaSource &materiaSource);
		~MateriaSource();

		void learnMateria(AMateria *materia);
		AMateria *createMateria(const std::string &type);
};

#endif