#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		PmergeMe(void);

		std::vector<unsigned int> _arr;

		std::vector<unsigned int> _parse(const std::string &str);

	public:
		explicit PmergeMe(const std::string &str);
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);
		~PmergeMe();

		std::vector<unsigned int> getValues(void) const;
		void sort(void);
		void mergeSort(std::deque<unsigned int> &buffer, size_t left, size_t right);
		void mergeInsert(std::deque<unsigned int> &buffer, size_t left, size_t mid, size_t right);
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
	for(unsigned long i = 0; i < vec.size(); i++)
	{
		if(i > 0)
			out << std::string(" ");

		out << vec[i];
	}

	return out;
}

#endif
