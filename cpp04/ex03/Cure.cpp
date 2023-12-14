#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(const Cure &cure): AMateria(cure) {}

Cure &Cure::operator=(const Cure &cure)
{
	if (this == &cure)
		return *this;

	AMateria::operator=(cure);

	return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone(void) const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
