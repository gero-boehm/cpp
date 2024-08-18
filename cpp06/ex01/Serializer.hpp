#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>

struct Data
{
	std::string content;
	size_t contentLength;
	bool whatever;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &serializer);
		Serializer &operator=(const Serializer &serializer);

	public:
		~Serializer();

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
