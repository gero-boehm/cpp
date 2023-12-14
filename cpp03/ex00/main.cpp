#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("b");
	ClapTrap c(b);

	c = a;

	a.attack("somebody");
	a.takeDamage(0);
	a.takeDamage(5);
	a.takeDamage(3);
	a.beRepaired(3);
	a.takeDamage(7);
	a.beRepaired(10);
	a.takeDamage(2);

	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.attack("somebody");
	b.takeDamage(19);
	b.takeDamage(1);
	b.attack("sombody");

	return 0;
}
