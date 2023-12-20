#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->content = "Hello World!";
	data->contentLength = data->content.length();
	data->whatever = true;

	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);

	std::cout << "data->content: " << data->content << std::endl;
	std::cout << "data->contentLength: " << data->contentLength << std::endl;
	std::cout << "data->whatever: " << data->whatever << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "data2->content: " << data2->content << std::endl;
	std::cout << "data2->contentLength: " << data2->contentLength << std::endl;
	std::cout << "data2->whatever: " << data2->whatever << std::endl;

	delete data;

	return 0;
}
