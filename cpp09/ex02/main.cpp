#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "PmergeMe.hpp"

const std::string formatTime(double time)
{
	std::stringstream stream;

	stream << std::fixed << std::setprecision(6) << time << "µs";

	return stream.str();
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "Invalid argument count" << std::endl;
		return 1;
	}

	std::stringstream stream("");

	for(int i = 1; i < argc; i++)
		stream << argv[i] << " ";

	try
	{
		PmergeMe<std::vector<unsigned int> > vec(stream.str());

		std::cout << "Before:" << std::endl;
		std::cout << vec.getValues() << std::endl;

		double vec_time = vec.sort();

		std::cout << "After:" << std::endl;
		std::cout << vec.getValues() << std::endl;

		PmergeMe<std::deque<unsigned int> > deq(stream.str());
		double deq_time = deq.sort();

		std::cout << "Time to process a range of " << vec.getSize() << " elements with std::vector : " << formatTime(vec_time) << std::endl;
		std::cout << "Time to process a range of " << deq.getSize() << " elements with std::deque  : " << formatTime(deq_time) << std::endl;

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
