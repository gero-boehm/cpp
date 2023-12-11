#include <iostream>
#include <string>
#include <cctype>

void to_upper(std::string &str)
{
	for(size_t i = 0; i < str.length(); i++)
		std::cout << static_cast<char>(toupper(str[i]));
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}

	for(int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		to_upper(str);
		std::cout << ' ';
	}

	std::cout << std::endl;

	return 0;
}
