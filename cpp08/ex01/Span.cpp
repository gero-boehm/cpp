#include <algorithm>
#include <limits>
#include "Span.hpp"

Span::Span(void): _capacity(0) {}

Span::Span(unsigned int N)
{
	if(N < 2)
		throw Span::CapacityTooLow();

	_capacity = N;
}

Span::Span(const Span &span)
{
	*this = span;
}

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return *this;

	_capacity = span._capacity;
	_elements = span._elements;

	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if(_elements.size() == _capacity)
		throw Span::MaxCapacityReached();

	_elements.push_back(num);
}

unsigned int Span::shortestSpan(void) const
{
	if(_elements.size() < 2)
		throw Span::NoSpanPossible();

	std::vector<int> tmp = _elements;
	unsigned int shortest = std::numeric_limits<unsigned int>::max();

	std::sort(tmp.begin(), tmp.end());

	for(unsigned long i = 1; i < tmp.size(); i++)
	{
		unsigned int span = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);

		if(span < shortest)
			shortest = span;

		if(shortest == 0)
			return 0;
	}

	return shortest;
}

unsigned int Span::longestSpan(void) const
{
	if(_elements.size() < 2)
		throw Span::NoSpanPossible();

	int min = *std::min_element(_elements.begin(), _elements.end());
	int max = *std::max_element(_elements.begin(), _elements.end());

	return static_cast<unsigned int>(max - min);
}

const char *Span::MaxCapacityReached::what() const throw()
{
	return "Cannot insert number(s). Max capacity reached";
}

const char *Span::CapacityTooLow::what() const throw()
{
	return "Max capacity must be greater than 1";
}

const char *Span::NoSpanPossible::what() const throw()
{
	return "Cannot find span with less than 2 numbers";
}
