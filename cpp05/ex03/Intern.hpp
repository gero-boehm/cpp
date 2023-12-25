#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
