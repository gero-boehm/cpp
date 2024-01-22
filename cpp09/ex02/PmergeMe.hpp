#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stdexcept>
# include <algorithm>
# include <cstdlib>
# include <cerrno>
# include <ctime>
# include <cmath>
# include <limits>
# include <iomanip>
# include "Composite.hpp"

template <typename T>
class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &pmergeMe)
		{
			(void) pmergeMe;
		}

		PmergeMe &operator=(const PmergeMe &pmergeMe)
		{
			(void) pmergeMe;

			return *this;
		}

		T _parse(const char **nums)
		{
			T parsed;

			try
			{
				while (*nums != NULL)
				{
					_parseNum(*nums, parsed);
					nums++;
				}
			}
			catch (std::exception &e)
			{
				for (typename T::iterator it = parsed.begin(); it != parsed.end(); it++)
					delete *it;

				throw;
			}

			return parsed;
		}

		void _parseNum(const char *str, T &parsed)
		{
			char *end;

			errno = 0;
			long num = strtol(str, &end, 10);

			if (*end != '\0')
				throw std::runtime_error("Invalid input: invalid symbol detected");
			if (errno == ERANGE || num > std::numeric_limits<int>::max())
				throw std::runtime_error("Invalid input: overflow detected");
			if (num < 0)
				throw std::runtime_error("Invalid input: negative number detected");

			parsed.push_back(new Number(num));
		}

		void _sort(T &arr)
		{
			size_t size = arr.size();

			if(size <= 1)
				return;

			T pair_arr;
			T main_arr;
			T pend_arr;

			_makePairs(arr, pair_arr, size);
			_sort(pair_arr);
			_prepareChains(arr, pair_arr, main_arr, pend_arr, size);
			_insertPend(main_arr, pend_arr);

			arr.swap(main_arr);
		}

		void _makePairs(T &arr, T &pair_arr, size_t size)
		{
			for(unsigned long i = 1; i < size; i += 2)
			{
				Pair *pair = new Pair(arr[i - 1], arr[i]);
				pair_arr.push_back(pair);
			}
		}

		void _prepareChains(T &arr, T &pair_arr, T &main_arr, T &pend_arr, size_t size)
		{
			main_arr.push_back(dynamic_cast<const Pair *>(*pair_arr.begin())->getMin());
			for(typename T::iterator it = pair_arr.begin(); it != pair_arr.end(); it++)
			{
				main_arr.push_back(dynamic_cast<const Pair *>(*it)->getMax());
				pend_arr.push_back(dynamic_cast<const Pair *>(*it)->getMin());
				delete dynamic_cast<const Pair *>(*it);
			}

			if(size % 2 == 1)
				pend_arr.push_back(*arr.rbegin());
		}

		void _insertPend(T &main_arr, T &pend_arr)
		{
			for(unsigned long k = 2; true; k++)
			{
				unsigned long start = _getTK(k - 1) - 1;
				unsigned long end = _getTK(k) - 1;

				if(end >= pend_arr.size())
					end = pend_arr.size() - 1;

				for(unsigned long i = end; i > start; i--)
				{
					unsigned long index = _binarySearch(main_arr, 0, pow(2, k) - 1, pend_arr[i]);
					main_arr.insert(main_arr.begin() + index, pend_arr[i]);
				}

				if(end == pend_arr.size() - 1)
					break;
			}
		}

		unsigned long _getTK(unsigned long k)
		{
			return (pow(2, k + 1) + pow(-1, k)) / 3;
			// return (pow(2, k) - pow(-1, k)) / 3;
		}

		unsigned long _binarySearch(T &arr, unsigned long startIndex, unsigned long endIndex, const Composite *value)
		{

			if(endIndex >= arr.size())
				endIndex = arr.size() - 1;

			while (startIndex <= endIndex) {
				unsigned long midIndex = (startIndex + endIndex) / 2;
				const Composite *midValue = arr[midIndex];

				if (*midValue == *value)
					return midIndex;
				if (*value < *midValue)
				{
					if (midIndex == 0)
						return 0;

					endIndex = midIndex - 1;
				}
				else
					startIndex = midIndex + 1;
			}

			return startIndex;
		}

		const std::string _getTime(std::clock_t &start, std::clock_t &end)
		{
			std::stringstream stream;

			double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

			stream << std::fixed << std::setprecision(3) << time << "µs";

			return stream.str();
		}

	public:
		PmergeMe(void) {}
		~PmergeMe() {}

		void sort(const char **nums, const std::string &type)
		{
			bool isVector = type == "vector";

			std::clock_t start = std::clock();

			T numbers = _parse(nums);

			if(isVector)
			{
				std::cout << "Before:" << std::endl;
				std::cout << numbers << std::endl;
			}

			_sort(numbers);

			if(isVector)
			{
				std::cout << "After:" << std::endl;
				std::cout << numbers << std::endl;
			}

			size_t count = numbers.size();

			for (unsigned long i = 0; i < numbers.size(); i++)
				delete numbers[i];

			std::clock_t end = std::clock();

			std::cout << "Time to process a range of " << count << " elements with std::" << type << " : " << _getTime(start, end) << std::endl;

		}
};

std::ostream &operator<<(std::ostream &out, const std::vector<const Composite *> &arr)
{
	for(unsigned long i = 0; i < arr.size(); i++)
	{
		if(i > 0)
			out << ' ';

		out << arr[i]->getValue();
	}

	return out;
}

std::ostream &operator<<(std::ostream &out, const std::deque<const Composite *> &arr)
{
	for(unsigned long i = 0; i < arr.size(); i++)
	{
		if(i > 0)
			out << ' ';

		out << arr[i]->getValue();
	}

	return out;
}

#endif
