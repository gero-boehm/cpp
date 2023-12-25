#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORM_COUNT 3

Intern::Intern(void) {}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string formNames[FORM_COUNT] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(*forms[FORM_COUNT])(const std::string &target) = {&RobotomyRequestForm::create, &PresidentialPardonForm::create, &ShrubberyCreationForm::create};

	for (int i = 0; i < FORM_COUNT; i++)
	{
		if(formNames[i] != formName)
			continue;

		std::cout << "Intern creates " << formName << std::endl;
		return forms[i](target);
	}

	std::cerr << "Form " << formName << " does not exist" << std::endl;
	return NULL;
}
