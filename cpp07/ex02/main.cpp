#include <iostream>
#include <stdexcept>
#include "Array.hpp"


class Test
{
	public:
		int get(void)
		{
			return 42;
		}
};

std::ostream &operator<<(std::ostream &out, Test &test)
{
	out << test.get();
	return out;
}

std::ostream &operator<<(std::ostream &out, Array<Test> &arr)
{
	out << arr[0];
	return out;
}

int main(void)
{
	Array<int> a;
	Array<Test> b;

	std::cout << a.size() << std::endl;

	try
	{
		std::cout << b << std::endl;
	} catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<Test> c(3);
	std::cout << c << std::endl;

	Array<int> d(1);
	d[0] = 5;
	Array<int> e(d);

	std::cout << "before" << std::endl;
	std::cout << d[0] << std::endl;
	std::cout << e[0] << std::endl;

	d[0] = 1;
	e[0] = 3;

	std::cout << "after" << std::endl;
	std::cout << d[0] << std::endl;
	std::cout << e[0] << std::endl;

	return 0;
}
