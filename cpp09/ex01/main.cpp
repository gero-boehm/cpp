#include <iostream>
#include <stdexcept>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Incorrect argument count" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn(argv[1]);
		int result = rpn.calculate();

		std::cout << result << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
