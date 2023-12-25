#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		const std::string &getName(void) const;
		unsigned int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(AForm &form) const;
		void executeForm(const AForm &form) const;

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
