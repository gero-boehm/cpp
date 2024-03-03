#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExecute;

	public:
		Form(void);
		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(const Form &form);
		Form &operator=(const Form &form);
		~Form();

		const std::string &getName(void) const;
		bool isSigned(void) const;
		unsigned int getGradeToSign(void) const;
		unsigned int getGradeToExecute(void) const;
		void beSigned(const Bureaucrat &bureaucrat);

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

		class AlreadySigned: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif
