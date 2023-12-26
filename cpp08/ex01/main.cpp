#include <iostream>
#include "Span.hpp"

int main(void)
{
	Span span(10);

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;


	Span span2 = span;

	span.addNumber(100);

	std::cout << span2.shortestSpan() << std::endl;
	std::cout << span2.longestSpan() << std::endl;

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;

	return 0;
}