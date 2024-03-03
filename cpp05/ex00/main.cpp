#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Bob", 150);
		std::cout << *bureaucrat << std::endl;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat << std::endl;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat << std::endl;

		delete bureaucrat;
	}

	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Bob", 0);
		std::cout << *bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "Cannot instatiate because: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Bob", 151);
		std::cout << *bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "Cannot instatiate because: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Bob", 1);
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Cannot increment grade because: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Bob", 150);
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Cannot decrement grade because: " << e.what() << std::endl;
	}

	return 0;
}
