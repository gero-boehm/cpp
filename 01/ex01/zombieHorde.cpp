#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if(N <= 0)
	{
		std::cout << "N must be positive and non-zero" << std::endl;
		return NULL;
	}

	Zombie *zombies = new Zombie[N];
	for(int i = 0; i < N; i++)
		zombies[i].set_name(name);

	return zombies;
}
