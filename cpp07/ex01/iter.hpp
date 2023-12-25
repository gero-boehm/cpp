#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(T *array, size_t size, F fn)
{
	for(unsigned long i = 0; i < size; i++)
		fn(array[i]);
}

#endif
