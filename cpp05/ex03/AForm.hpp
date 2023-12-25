#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const unsigned int _gradeToSign;
		const unsigned int _gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(const AForm &Aform);
		AForm &operator=(const AForm &Aform);
		virtual ~AForm();

		const std::string &getName(void) const;
		bool isSigned(void) const;
		unsigned int getGradeToSign(void) const;
		unsigned int getGradeToExecute(void) const;
		void beSigned(const Bureaucrat &bureaucrat);

		virtual void execute(const Bureaucrat &bureaucrat) const = 0;

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

		class NotSigned: public std::exception
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

#endif
