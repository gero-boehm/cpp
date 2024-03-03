#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		Bureaucrat bureaucrat("Bob", 150);
		Form form("Application Form", 150, 150);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}

	{
		Bureaucrat worker("Worker", 140);
		Bureaucrat manager("Manager", 100);
		Bureaucrat boss("Boss", 50);
		Form form1("Useless Form", 150, 1);
		std::cout << form1 << std::endl;
		Form form2("Useful Form", 100, 1);
		std::cout << form2 << std::endl;
		Form form3("Important Form", 50, 1);
		std::cout << form3 << std::endl;
		worker.signForm(form1);
		worker.signForm(form2);
		manager.signForm(form1);
		manager.signForm(form2);
		manager.signForm(form3);
		boss.signForm(form2);
		boss.signForm(form3);
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
	}

	return 0;
}
