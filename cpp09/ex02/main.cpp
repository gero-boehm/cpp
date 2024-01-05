#include <iostream>
#include <sstream>
#include <stdexcept>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "Invalid argument count" << std::endl;
		return 1;
	}

	(void) argv;

	std::stringstream stream("");

	for(int i = 1; i < argc; i++)
		stream << argv[i] << " ";

	try
	{
		PmergeMe sort(stream.str());

		std::cout << "Before:" << std::endl;
		std::cout << sort.getValues() << std::endl;

		sort.sort();

		std::cout << "After:" << std::endl;
		std::cout << sort.getValues() << std::endl;

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}


// #include <iostream>
// #include <vector>
// #include <deque>
// #include <algorithm>



// int main() {
// 	std::vector<int> arr;
// 	arr.push_back(12);
// 	arr.push_back(56);
// 	arr.push_back(8);
// 	arr.push_back(1);
// 	arr.push_back(8);

// 	std::cout << "Before sorting:" << std::endl;
// 	for (size_t i = 0; i < arr.size(); i++) {
// 		std::cout << arr[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	fordJohnsonMergeInsert(arr);

// 	std::cout << "After sorting:" << std::endl;
// 	for (size_t i = 0; i < arr.size(); i++) {
// 		std::cout << arr[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	return 0;
// }
