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

template<typename T>
class PmergeMe
{
	private:
		PmergeMe(void) {}

		T _arr;

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

		T _parse(const std::string &str)
		{
			T nums;

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

		T getValues(void) const
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

			T buffer(_arr.size());
			mergeSort(buffer, 0, _arr.size() - 1);

			std::clock_t end = std::clock();

			return static_cast<double>(end - start) / CLOCKS_PER_SEC;
		}

		void mergeSort(T &buffer, size_t left, size_t right)
		{
			if (left < right)
			{
				size_t mid = left + (right - left) / 2;

				mergeSort(buffer, left, mid);
				mergeSort(buffer, mid + 1, right);

				mergeInsert(buffer, left, mid, right);
			}
		}

		void mergeInsert(T &buffer, size_t left, size_t mid, size_t right)
		{
			size_t i = left;
			size_t j = mid + 1;
			size_t k = left;

			while (i <= mid && j <= right)
			{
				if (_arr[i] <= _arr[j])
				{
					buffer[k++] = _arr[i++];
				}
				else
				{
					buffer[k++] = _arr[j++];
				}
			}

			while (i <= mid)
			{
				buffer[k++] = _arr[i++];
			}

			while (j <= right)
			{
				buffer[k++] = _arr[j++];
			}

			for (size_t idx = left; idx <= right; idx++)
			{
				_arr[idx] = buffer[idx];
			}
		}
};


template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &arr)
{
	for(unsigned long i = 0; i < arr.size(); i++)
	{
		if(i > 0)
			out << " ";

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
			out << " ";

		out << arr[i];
	}

	return out;
}

#endif
