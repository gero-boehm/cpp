#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon Form", 25, 5), _target("Undefined") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm): AForm(presidentialPardonForm), _target(presidentialPardonForm._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
	AForm::operator=(presidentialPardonForm);
	const_cast<std::string&>(_target) = presidentialPardonForm._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	AForm::execute(bureaucrat);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}