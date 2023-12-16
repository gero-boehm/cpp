#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

# define MAX_CAPACITY 1000

class Floor
{

	private:
		AMateria *_materias[MAX_CAPACITY];
		int _capacity;

	public:
		Floor(void);
		Floor(const Floor &floor);
		Floor &operator=(const Floor &floor);
		~Floor();

		void addMateria(AMateria *materia);
		static Floor &getInstance(void);

};

#endif