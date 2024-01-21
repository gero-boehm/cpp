#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define MAX_IDEAS 100

class Brain
{
	private:
		std::string ideas[MAX_IDEAS];

	public:
		Brain(void);
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		~Brain();

};

#endif
