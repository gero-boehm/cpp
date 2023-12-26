#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>
# include <sstream>

template <typename T>
typename T::iterator easyfind(T &cont, int i)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), i);

	if(it != cont.end())
		return it;

	std::ostringstream stream;
	stream << "Value " << i << " not contained in container";

	throw std::runtime_error(stream.str());
}

#endif
