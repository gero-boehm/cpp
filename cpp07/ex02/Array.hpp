#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_elements;
		size_t _size;

	public:
		Array(void): _elements(new T[0]), _size(0) {}
		Array(size_t n): _elements(new T[n]), _size(n) {}
		Array(const Array &array): _elements(new T[array.size()]), _size(array.size())
		{
			*this = array;
		}
		Array &operator=(const Array &array)
		{
			if(this == &array)
				return *this;

			for(unsigned long i = 0; i < array.size(); i++)
				_elements[i] = array[i];

			return *this;
		}
		~Array()
		{
			delete[] _elements;
			_elements = NULL;
			_size = 0;
		}

		T &operator[](unsigned long i) const
		{
			if(i >= _size)
				throw std::runtime_error("index out of range");

			return _elements[i];
		}

		size_t size(void) const
		{
			return _size;
		}
};

#endif
