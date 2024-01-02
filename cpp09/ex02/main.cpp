#include <iostream>
#include <sstream>
#include <stdexcept>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{

	try
	{
		PmergeMe sort(" 12 56 8 1 8   ");

		// std::cout << "Before:" << std::endl;
		// std::cout << sort.getValues() << std::endl;
		// std::cout << "After:" << std::endl;
		std::cout << sort.sort() << std::endl;

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}