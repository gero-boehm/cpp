#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <string>
#include <vector>

class PmergeMe
{
	private:
		PmergeMe(void);

		std::vector<unsigned int> _vec;

		std::vector<unsigned int> _parse(const std::string &str);

	public:
		explicit PmergeMe(const std::string &str);
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);
		~PmergeMe();

		// const std::vector<unsigned int> sort(void) const;
		std::vector<unsigned int> getValues(void) const;
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
