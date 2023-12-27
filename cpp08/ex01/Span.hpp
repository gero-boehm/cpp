#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
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

		template <typename T>
		void addNumbers(const T &start, const T &end)
		{
			if(_elements.size() + std::distance(start, end) > _capacity)
				throw Span::MaxCapacityReached();

			_elements.insert(_elements.end(), start, end);
		}

		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		unsigned int getSize(void) const;

		const int &operator[](unsigned int index) const;

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

		class IndexOutOfRange: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Span &span);

#endif
