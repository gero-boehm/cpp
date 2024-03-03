#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));

	{
		Bureaucrat bureaucrat("Bob", 1);
		ShrubberyCreationForm form("Garden");
		bureaucrat.executeForm(form);
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}

	{
		Bureaucrat bureaucrat("Jimmy", 46);
		RobotomyRequestForm form("Fry");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.incrementGrade();
		bureaucrat.executeForm(form);
	}

	{
		Bureaucrat lois("Lois", 25);
		Bureaucrat peter("Peter", 1);
		PresidentialPardonForm form("Quagmire");
		lois.signForm(form);
		lois.executeForm(form);
		peter.executeForm(form);
	}

	{
		// ShrubberyCreationForm form;
		// RobotomyRequestForm form;
		// PresidentialPardonForm form;
	}

	return 0;
}
