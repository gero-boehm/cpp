#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	private:

	public:
		Brain(void);
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		~Brain();

};

#endif