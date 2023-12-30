#include <iostream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		std::cout << "No input file provided" << std::endl;
		return 1;
	}
	if(argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange exchange("data.csv", argv[1]);
		exchange.calculate();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
