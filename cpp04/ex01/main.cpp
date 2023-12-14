#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define MAX_ANIMALS 10

int main(void)
{
	Animal *animals[MAX_ANIMALS];

	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < MAX_ANIMALS; i++)
		delete animals[i];


	// deep copy test
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	Cat cat3(cat1);

	std::cout << "cat1: " << cat1.getBrain() << std::endl;
	std::cout << "cat2: " << cat2.getBrain() << std::endl;
	std::cout << std::boolalpha << (cat1.getBrain() == cat2.getBrain()) << std::endl;
	std::cout << "cat1: " << cat1.getBrain() << std::endl;
	std::cout << "cat3: " << cat3.getBrain() << std::endl;
	std::cout << std::boolalpha << (cat1.getBrain() == cat3.getBrain()) << std::endl;

	Dog dog1;
	Dog dog2;
	dog2 = dog1;
	Dog dog3(dog1);

	std::cout << "dog1: " << dog1.getBrain() << std::endl;
	std::cout << "dog2: " << dog2.getBrain() << std::endl;
	std::cout << std::boolalpha << (dog1.getBrain() == dog2.getBrain()) << std::endl;
	std::cout << "dog1: " << dog1.getBrain() << std::endl;
	std::cout << "dog3: " << dog3.getBrain() << std::endl;
	std::cout << std::boolalpha << (dog1.getBrain() == dog3.getBrain()) << std::endl;

	return 0;
}