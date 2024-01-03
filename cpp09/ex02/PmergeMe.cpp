#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cerrno>
#include <sstream>
#include <stdexcept>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const std::string &str): _vec(PmergeMe::_parse(str)) {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe)
{
	*this = pmergeMe;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe)
{
	if(this == &pmergeMe)
		return *this;

	_vec = pmergeMe._vec;

	return *this;
}

PmergeMe::~PmergeMe() {}

const std::vector<unsigned int> PmergeMe::_parse(const std::string &str)
{
	std::vector<unsigned int> nums;

	std::istringstream stream(str);
	std::string token;

	while(stream >> token) {
		char *end;

		errno = 0;
		long num = strtol(token.c_str(), &end, 10);

		if(*end != '\0')
			throw std::runtime_error("Invalid input: invalid symbol detected");
		if(errno == ERANGE)
			throw std::runtime_error("Invalid input: overflow detected");
		if(num < 0)
			throw std::runtime_error("Invalid input: negative number detected");

		nums.push_back(static_cast<unsigned int>(num));
	}

	return nums;
}

const std::vector<unsigned int> PmergeMe::getValues(void) const
{
	return _vec;
}


// void merge(std::vector<unsigned int> &arr, std::deque<unsigned int> &left, std::deque<unsigned int> &right)
// {
// 	size_t l = 0, r = 0, k = 0;
// 	while (l < left.size() && r < right.size()) {
// 		if (left[l] < right[r]) {
// 			arr[k++] = left[l++];
// 		} else {
// 			arr[k++] = right[r++];
// 		}
// 	}

// 	while (l < left.size()) {
// 		arr[k++] = left[l++];
// 	}

// 	while (r < right.size()) {
// 		arr[k++] = right[r++];
// 	}
// }

// void mergeInsertionSort(std::vector<unsigned int> &arr)
// {
// 	if (arr.size() <= 1) {
// 		return;
// 	}

// 	std::deque<unsigned int> left, right;
// 	for (size_t i = 0; i < arr.size(); i++) {
// 		if (i % 2 == 0) {
// 			left.push_back(arr[i]);
// 		} else {
// 			right.push_back(arr[i]);
// 		}
// 	}

// 	std::vector<unsigned int> leftVec(left.begin(), left.end());
// 	std::vector<unsigned int> rightVec(right.begin(), right.end());

// 	mergeInsertionSort(leftVec);
// 	mergeInsertionSort(rightVec);

// 	std::cout << leftVec << std::endl;
// 	std::cout << rightVec << std::endl;

// 	std::deque<unsigned int> leftDeque(leftVec.begin(), leftVec.end());
// 	std::deque<unsigned int> rightDeque(rightVec.begin(), rightVec.end());

// 	merge(arr, left, right);
// }

// const std::vector<unsigned int> PmergeMe::sort(void) const
// {
// 	std::vector<unsigned int> vec = const_cast<std::vector<unsigned int>&>(_vec);

// 	mergeInsertionSort(vec);

// 	return vec;
// }



// {5, 3, 1, 9, 8, 2, 7}

// 5 1 8 7
// 3 9 2

// 5 9 8 7
// 3 1 2


// 5 8
// 9 7

// 9 8
// 5 7

// 9
// 8

// 5
// 7

// 7
// 5
