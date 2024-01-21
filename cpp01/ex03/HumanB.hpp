#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(const std::string &name);
		~HumanB();

		void setWeapon(Weapon &weapon);
		void attack();
};

#endif
