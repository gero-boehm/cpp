#include "AMateria.hpp"

AMateria::AMateria(void): _type("undefined") {}

AMateria::AMateria(std::string const &type): _type(type) {}

AMateria::AMateria(const AMateria &materia)
{
	*this = materia;
}

AMateria &AMateria::operator=(const AMateria &materia)
{
	if (this == &materia)
		return *this;

	_type = materia._type;

	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType(void) const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* " << target.getName() << " was hit by a gust of hot air *" << std::endl;
}
