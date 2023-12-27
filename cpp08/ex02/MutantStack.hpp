#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:

		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack<T>(void) {}

		MutantStack<T>(const MutantStack<T> &mutantStack)
		{
			*this = mutantStack;
		}

		MutantStack<T> &operator=(const MutantStack<T> &mutantStack)
		{
			if(this == &mutantStack)
				return *this;

			this->c = mutantStack.c;

			return *this;
		}

		~MutantStack<T>() {}

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}
};

#endif
