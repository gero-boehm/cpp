#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &animal);
		virtual Animal &operator=(const Animal &animal);
		virtual ~Animal();

		const std::string &getType(void) const;

		virtual void makeSound(void) const;

};

#endif
