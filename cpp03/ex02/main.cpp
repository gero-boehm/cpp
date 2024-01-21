#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap("FragTrap");

	fragTrap.attack("target");
	fragTrap.takeDamage(5);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();
	return 0;
}
