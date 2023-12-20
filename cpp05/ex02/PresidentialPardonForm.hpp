#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		const std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);
		~PresidentialPardonForm();

		void execute(const Bureaucrat &bureaucrat) const;
};

#endif
