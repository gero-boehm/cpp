#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		PresidentialPardonForm(void);

		const std::string _target;

	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);
		~PresidentialPardonForm();

		static AForm *create(const std::string &target);
		void execute(const Bureaucrat &bureaucrat) const;
};

#endif
