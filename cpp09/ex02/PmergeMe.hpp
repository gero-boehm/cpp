#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <cmath>
#include "Composite.hpp"

template<template<typename...> class C, typename T>
class PmergeMe
{
	private:
		PmergeMe(void) {}

		C<T> _arr;

	public:
		PmergeMe(const std::string &str)
		{
			_arr = _parse(str);
		}

		PmergeMe(const PmergeMe &pmergeMe)
		{
			*this = pmergeMe;
		}

		PmergeMe &operator=(const PmergeMe &pmergeMe)
		{
			if (this == &pmergeMe)
				return *this;

			_arr = pmergeMe._arr;

			return *this;
		}

		~PmergeMe() {}

		C<T> _parse(const std::string &str)
		{
			C<T> nums;

			std::istringstream stream(str);
			std::string token;

			while (stream >> token)
			{
				char *end;

				errno = 0;
				long num = strtol(token.c_str(), &end, 10);

				if (*end != '\0')
					throw std::runtime_error("Invalid input: invalid symbol detected");
				if (errno == ERANGE)
					throw std::runtime_error("Invalid input: overflow detected");
				if (num < 0)
					throw std::runtime_error("Invalid input: negative number detected");

				nums.push_back(static_cast<unsigned int>(num));
			}

			return nums;
		}

		void _sort(C<Composite &> &arr)
		{
			if(arr.size() <= 1)
				return;

			size_t size = arr.size();

			C<Composite &> pair_arr(size / 2);
			C<Composite &> main_arr(size);
			C<Composite &> pend_arr(size / 2 + size % 2);

			_makePairs(arr, pair_arr, size);
			_sort(pair_arr);
			_prepareChains(pair_arr, main_arr, pend_arr, size);
			_insertPend(main_arr, pend_arr);

			arr = main_arr;
		}

		void _makePairs(C<Composite &> &arr, C<Composite &> &pair_arr, size_t size)
		{
			for(unsigned long i = 0; i < size; i += 2)
			{
				Pair pair(arr[i], arr[i + 1]);
				pair_arr.push_back(pair);
			}
		}

		void _prepareChains(C<Composite &> &pair_arr, C<Composite &> &main_arr, C<Composite &> &pend_arr, size_t size)
		{
			main_arr.push_back((*pair_arr.begin()).getMin());
			for(typename C<Composite &>::iterator it = pair_arr.begin(); it != pair_arr.end(); it++)
			{
				main_arr.push_back((*it).getMax());
				pend_arr.push_back((*it).getMin());
			}

			if(size % 2 == 1)
			{
				pend_arr.push_back(*pair_arr.rbegin());
			}
		}

		void _insertPend(C<Composite &> &main_arr, C<Composite &> &pend_arr)
		{

			typename C<Composite &>::iterator lower = pend_arr.begin() + 1;

			for(unsigned long k = 2; true; k++)
			{
				typename C<Composite &>::iterator upper = pend_arr.begin() + _getTK(k);

				if(upper > pend_arr.end())
					upper = pend_arr.end();

				typename C<Composite &>::iterator it = upper;

				while(it > lower)
				{
					unsigned long index = _binarySearch(main_arr, 0, pow(2, k) - 1, *it);
					main_arr.insert(main_arr.begin() + index, *it);
				}

				if(upper == pend_arr.end())
					break;

				lower = upper + 1;
			}
		}

		unsigned long _getTK(unsigned long k)
		{
			return (pow(2, k + 1) + pow(-1, k)) / 3;
		}

		unsigned long _binarySearch(C<Composite &> &arr, unsigned long startIndex, unsigned long endIndex, Composite &value)
		{
			if(startIndex > endIndex)
				return startIndex;

			unsigned long middleIndex = (startIndex + endIndex) / 2;

			if(arr[middleIndex] == value)
				return middleIndex;
			else if(arr[middleIndex] > value)
				return _binarySearch(arr, startIndex, middleIndex - 1, value);
			else
				return _binarySearch(arr, middleIndex + 1, endIndex, value);
		}

		C<T> getValues(void) const
		{
			return _arr;
		}

		size_t getSize(void) const
		{
			return _arr.size();
		}

		double sort(void)
		{
			std::clock_t start = std::clock();

			C<Composite &> numbers(_arr.size());

			for (typename C<T>::iterator it = _arr.begin(); it != _arr.end(); it++)
				numbers.push_back(Number(*it));

			_sort(numbers);

			or (unsigned long i = 0; i < numbers.size(); i++)
				_arr[i] = numbers[i].getValue();

			std::clock_t end = std::clock();

			return static_cast<double>(end - start) / CLOCKS_PER_SEC;
		}
};


template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &arr)
{
	for(unsigned long i = 0; i < arr.size(); i++)
	{
		if(i > 0)
			out << ' ';

		out << arr[i];
	}

	return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::deque<T> &arr)
{
	for(unsigned long i = 0; i < arr.size(); i++)
	{
		if(i > 0)
			out << ' ';

		out << arr[i];
	}

	return out;
}

#endif
