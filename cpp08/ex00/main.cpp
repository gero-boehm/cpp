#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include "easyfind.hpp"

template <typename T>
void find(const std::string &type, T &cont)
{
	try
	{
		typename T::iterator it = easyfind(cont, rand() % 20);
		std::cout << type << ": Value " << *it << " found at index " << std::distance(cont.begin(), it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << type << ": " << e.what() << '\n';
	}
}

int main(void)
{
	srand(time(NULL));

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *end = arr + sizeof(arr) / sizeof(arr[0]);

	std::vector<int> vec(arr, end);
	std::deque<int> deq(arr, end);
	std::list<int> lst(arr, end);

	find("vector", vec);
	find("vector", vec);
	find("vector", vec);

	find("deque", deq);
	find("deque", deq);
	find("deque", deq);

	find("list", lst);
	find("list", lst);
	find("list", lst);

	return 0;
}
