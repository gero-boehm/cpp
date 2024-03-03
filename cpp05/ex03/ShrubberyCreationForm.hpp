#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		ShrubberyCreationForm(void);

		const std::string _target;

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);
		~ShrubberyCreationForm();

		static AForm *create(const std::string &target);
		void execute(const Bureaucrat &bureaucrat) const;
};

#endif
