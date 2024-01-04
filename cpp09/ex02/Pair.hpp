#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>
# include <sstream>
# include <deque>

template <typename T>
class Pair
{
	private:
		Pair(void);

		std::deque<T> _values;

	public:
		explicit Pair(const T &v)
		{
			_values.push_back(v);
		}

		explicit Pair(const T &v1, const T &v2)
		{
			_values.push_back(v1);

			if(v1 > v2)
				_values.push_back(v2);
			else
				_values.push_front(v2);
		}

		Pair(const Pair &pair): _values(pair._values) {}

		Pair<T> &operator=(const Pair<T> &pair)
		{
			if (this == &pair)
				return *this;

			_values = pair._values;

			return *this;
		}

		~Pair() {}

		static Pair<T>

		const T &getMin(void) const
		{
			return _values.back();
		}

		const T &getMax(void) const
		{
			return _values.front();
		}

		size_t getSize(void) const
		{
			return _values.size();
		}

		bool operator<(const Pair<T> &pair) const
		{
			return getMax() < pair.getMax();
		}

		bool operator>(const Pair<T> &pair) const
		{
			return getMax() > pair.getMax();
		}
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Pair<T> &pair)
{
	std::ostringstream min;

	if(pair.getSize() > 1)
		min << pair.getMin();

	out << "(" << pair.getMax() << ", " << min.str() << ")";

	return out;
}

#endif
