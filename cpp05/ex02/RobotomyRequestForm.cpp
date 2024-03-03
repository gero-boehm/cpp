#include <cstdlib>
#include "RobotomyRequestForm.hpp"

// RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request Form", 72, 45), _target("Undefined") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm): AForm(robotomyRequestForm), _target(robotomyRequestForm._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
	AForm::operator=(robotomyRequestForm);
	const_cast<std::string&>(_target) = robotomyRequestForm._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	AForm::execute(bureaucrat);

	std::cout << "* drilling noises *" << std::endl;

	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << std::endl;
}
