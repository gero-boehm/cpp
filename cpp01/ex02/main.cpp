#include <iostream>
#include <string>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "address str " << &string << std::endl;
	std::cout << "address ptr " << stringPTR << std::endl;
	std::cout << "address ref " << &stringREF << std::endl;

	std::cout << "value str " << string << std::endl;
	std::cout << "value ptr " << *stringPTR << std::endl;
	std::cout << "value ref " << stringREF << std::endl;

	return 0;
}
