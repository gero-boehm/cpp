#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define INVENTORY_SIZE 4

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[INVENTORY_SIZE];

	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &character);
		Character &operator=(const Character &character);
		~Character();

		const std::string &getName(void) const;
		void equip(AMateria *materia);
		void unequip(int index);
		void use(int index, ICharacter &target);

};

#endif
