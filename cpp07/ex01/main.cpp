#include <iostream>
#include <string>
#include "iter.hpp"

void incrementChar(char &c)
{
	c++;
}

void incrementInt(int &i)
{
	i++;
}

int main(void)
{
	char str[] = "abcdef";
	int	num[] = {1, 2, 3, 4, 5, 6};
	size_t nums = sizeof(num) / sizeof(num[0]);

	iter(str, sizeof(str), incrementChar);
	iter(num, nums, incrementInt);

	std::cout << str << std::endl;

	for (unsigned long i = 0; i < nums; i++)
		std::cout << num[i];
	std::cout << std::endl;

	return 0;
}
