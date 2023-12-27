#include <iostream>
#include <vector>
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

	int arr[] = {59, 67, 10, 20, 1, 90};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));


	Span span3(20);
	span3.addNumber(3);
	span3.addNumber(100);
	span3.addNumber(657);

	std::cout << std::endl;
	std::cout << span3 << std::endl;
	std::cout << span3.shortestSpan() << std::endl;
	std::cout << span3.longestSpan() << std::endl;

	span3.addNumbers(vec.begin(), vec.end());

	std::cout << std::endl;
	std::cout << span3 << std::endl;
	std::cout << span3.shortestSpan() << std::endl;
	std::cout << span3.longestSpan() << std::endl;

	return 0;
}