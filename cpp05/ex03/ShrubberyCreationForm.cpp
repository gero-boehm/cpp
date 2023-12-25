#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery Creation Form", 145, 137), _target("Undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm): AForm(shrubberyCreationForm), _target(shrubberyCreationForm._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	AForm::operator=(shrubberyCreationForm);
	const_cast<std::string&>(_target) = shrubberyCreationForm._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

AForm *ShrubberyCreationForm::create(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	AForm::execute(bureaucrat);

	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open file");

	file << "	    ccee88oo" << std::endl;
	file << "  C8O8O8Q8PoOb o8oo" << std::endl;
	file << " dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "      \\//  /douUP" << std::endl;
	file << "        \\\\////" << std::endl;
	file << "         ||||" << std::endl;
	file << "         ||||" << std::endl;
	file << "    o    ||||" << std::endl;
	file << "   .|...//|||\\.,.." << std::endl;

	file.close();
}