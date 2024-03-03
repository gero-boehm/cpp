#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		RobotomyRequestForm(void);

		const std::string _target;

	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
		~RobotomyRequestForm();

		void execute(const Bureaucrat &bureaucrat) const;
};

#endif
