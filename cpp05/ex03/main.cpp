#include <cstdlib>
#include <ctime>
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	srand(time(NULL));

	const std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation", "some weird form"};

	Intern intern;

	for (int i = 0; i < 10; i++)
	{
		AForm * form = intern.makeForm(formNames[rand() % 4], "target");
		delete form;
	}

	return 0;
}
