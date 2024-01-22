#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

int main(int argc, const char **argv)
{
	if(argc < 2)
	{
		std::cerr << "Invalid argument count" << std::endl;
		return 1;
	}

	argv++;

	try
	{
		PmergeMe<std::vector<const Composite *> > vec;
		PmergeMe<std::deque<const Composite *> > deq;

		vec.sort(argv, "vector");
		deq.sort(argv, "deque");
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
