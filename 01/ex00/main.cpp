#include "Zombie.hpp"

int main()
{
	Zombie stack("Stackatony");
	stack.announce();

	Zombie *heap = newZombie("Heaperbole");
	heap->announce();
	delete heap;

	randomChump("Randomine");
	return 0;
}
