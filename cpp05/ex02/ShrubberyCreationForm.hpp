#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat &bureaucrat) const;
};

#endif
