#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span
{
	private:
		std::vector<int> _elements;
		unsigned int _capacity;

		Span(void);

	public:
		Span(unsigned int N);
		Span(const Span &span);
		Span &operator=(const Span &span);
		~Span();

		void addNumber(int num);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		class MaxCapacityReached: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class CapacityTooLow: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NoSpanPossible: public std::exception
		{
			public:
				const char *what() const throw();
		};

};

#endif
