// #include <iostream>
// #include <sstream>
// #include <stdexcept>
// #include "PmergeMe.hpp"
// #include "Pair.hpp"

// int main(int argc, char **argv)
// {
// 	if(argc != 2)
// 	{
// 		std::cerr << "Invalid argument count" << std::endl;
// 		return 1;
// 	}

// 	(void) argv;

// 	Pair<unsigned int> pair1(1, 3);
// 	Pair<unsigned int> pair2(5, 4);
// 	Pair<Pair<unsigned int> > pair3(pair1, pair2);
// 	Pair<unsigned int> pair4(8, 2);

// 	std::cout << pair1 << std::endl;
// 	std::cout << pair2 << std::endl;
// 	std::cout << pair3 << std::endl;


// 	// try
// 	// {
// 	// 	PmergeMe sort(" 12 56 8 1 8   ");


// 	// 	// std::cout << "Before:" << std::endl;
// 	// 	// std::cout << sort.getValues() << std::endl;
// 	// 	// std::cout << "After:" << std::endl;
// 	// 	// std::cout << sort.sort() << std::endl;

// 	// }
// 	// catch(std::exception &e)
// 	// {
// 	// 	std::cout << e.what() << std::endl;
// 	// }

// 	return 0;
// }


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

template<typename T>
void mergeInsert(std::vector<T>& arr, std::deque<T>& buffer, size_t left, size_t mid, size_t right) {
	size_t i = left;
	size_t j = mid + 1;
	size_t k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			buffer[k++] = arr[i++];
		} else {
			buffer[k++] = arr[j++];
		}
	}

	while (i <= mid) {
		buffer[k++] = arr[i++];
	}

	while (j <= right) {
		buffer[k++] = arr[j++];
	}

	for (size_t idx = left; idx <= right; idx++) {
		arr[idx] = buffer[idx];
	}
}

template<typename T>
void mergeSort(std::vector<T>& arr, std::deque<T>& buffer, size_t left, size_t right) {
	if (left < right) {
		size_t mid = left + (right - left) / 2;

		mergeSort(arr, buffer, left, mid);
		mergeSort(arr, buffer, mid + 1, right);

		mergeInsert(arr, buffer, left, mid, right);
	}
}

template<typename T>
void fordJohnsonMergeInsert(std::vector<T>& arr) {
	std::deque<T> buffer(arr.size());
	mergeSort(arr, buffer, 0, arr.size() - 1);
}

int main() {
	std::vector<int> arr;
	arr.push_back(12);
	arr.push_back(56);
	arr.push_back(8);
	arr.push_back(1);
	arr.push_back(8);

	std::cout << "Before sorting:" << std::endl;
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	fordJohnsonMergeInsert(arr);

	std::cout << "After sorting:" << std::endl;
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
