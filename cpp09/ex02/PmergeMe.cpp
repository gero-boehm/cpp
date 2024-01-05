#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cerrno>
#include <sstream>
#include <stdexcept>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const std::string &str): _arr(PmergeMe::_parse(str)) {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe)
{
	*this = pmergeMe;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe)
{
	if(this == &pmergeMe)
		return *this;

	_arr = pmergeMe._arr;

	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<unsigned int> PmergeMe::_parse(const std::string &str)
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

std::vector<unsigned int> PmergeMe::getValues(void) const
{
	return _arr;
}

void PmergeMe::sort(void)
{
	std::deque<unsigned int> buffer(_arr.size());
	mergeSort(buffer, 0, _arr.size() - 1);
}

void PmergeMe::mergeSort(std::deque<unsigned int> &buffer, size_t left, size_t right)
{
	if (left < right) {
		size_t mid = left + (right - left) / 2;

		mergeSort(buffer, left, mid);
		mergeSort(buffer, mid + 1, right);

		mergeInsert(buffer, left, mid, right);
	}
}

void PmergeMe::mergeInsert(std::deque<unsigned int> &buffer, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid + 1;
	size_t k = left;

	while (i <= mid && j <= right) {
		if (_arr[i] <= _arr[j]) {
			buffer[k++] = _arr[i++];
		} else {
			buffer[k++] = _arr[j++];
		}
	}

	while (i <= mid) {
		buffer[k++] = _arr[i++];
	}

	while (j <= right) {
		buffer[k++] = _arr[j++];
	}

	for (size_t idx = left; idx <= right; idx++) {
		_arr[idx] = buffer[idx];
	}
}
