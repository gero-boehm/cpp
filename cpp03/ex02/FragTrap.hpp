#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &scavTrap);
		FragTrap &operator=(const FragTrap &scavTrap);
		~FragTrap();

		void highFivesGuys(void);
};

#endif