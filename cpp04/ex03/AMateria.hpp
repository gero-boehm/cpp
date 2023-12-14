#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &materia);
		AMateria &operator=(const AMateria &materia);
		virtual ~AMateria();

		const std::string &getType(void) const;

		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);

};

#endif