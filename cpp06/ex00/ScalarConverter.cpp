#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <iomanip>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter)
{
	*this = scalarConverter;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter)
{
	(void) scalarConverter;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

t_components getComponents(const std::string& str)
{
	t_components components = {0, 0, 0, 0};

	for(size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == '.')
			components.decimal_point++;
		else if(str[i] >= '0' && str[i] <= '9')
			components.numbers++;
		else if(str[i] == '+' || str[i] == '-')
			components.signs++;
		else
			components.characters++;
	}

	return components;
}

e_type getType(const std::string& str)
{
	if(str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
		return FLOAT;
	if(str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
		return DOUBLE;

	t_components components = getComponents(str);

	if(components.decimal_point > 1)
		return INVALID;
	if(components.characters > 1)
		return INVALID;
	if(components.signs > 1)
		return INVALID;

	if (components.numbers > 0)
	{
		if(components.characters == 1 && str.end()[-1] == 'f')
			return FLOAT;
		if (components.characters > 0)
			return INVALID;
		if(components.decimal_point == 1)
			return DOUBLE;
		return INT;
	}

	if(str.length() == 1)
		return CHAR;

	return INVALID;
}

bool isSpecialCase(std::stringstream &stream, const std::string &appendix = "")
{
	const std::string str = stream.str();

	return str == ("nan" + appendix) || str == ("inf" + appendix) || str == ("+inf" + appendix) || str == ("-inf" + appendix);
}

std::string getFloatString(float f)
{
	std::stringstream stream;

	stream << f;
	if(stream.str().find('.') == std::string::npos)
		stream << ".0";
	stream << "f";

	return stream.str();
}

std::string getDoubleString(double d)
{
	std::stringstream stream;

	stream << d;
	if(stream.str().find('.') == std::string::npos)
		stream << ".0";

	return stream.str();
}

void convertChar(std::stringstream &stream)
{
	char c;
	stream >> c;
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if(isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: not displayable" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << getFloatString(f) << std::endl;
	std::cout << "double: " << getDoubleString(d) << std::endl;
}

void convertInt(std::stringstream &stream)
{
	int i;
	bool overflow = !(stream >> i);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if(overflow)
		std::cout << "char: impossible" << std::endl;
	else if(i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: overflow" << std::endl;
	else if(isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: not displayable" << std::endl;

	if(overflow)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	if(overflow)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << getFloatString(f) << std::endl;

	if(overflow)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << getDoubleString(d) << std::endl;
}

void convertFloatSpecial(std::stringstream &stream)
{
	std::string str = stream.str();

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str.erase(str.length() - 1) << std::endl;
}

void convertFloat(std::stringstream &stream)
{
	if(isSpecialCase(stream, "f"))
	{
		convertFloatSpecial(stream);
		return;
	}

	float f;
	bool overflow = !(stream >> f);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	if(overflow)
		std::cout << "char: impossible" << std::endl;
	else if(f < static_cast<float>(std::numeric_limits<char>::min()) || f > static_cast<float>(std::numeric_limits<char>::max()))
		std::cout << "char: overflow" << std::endl;
	else if(isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: not displayable" << std::endl;

	if(overflow)
		std::cout << "int: impossible" << std::endl;
	else if(f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	if(overflow)
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << getFloatString(f) << std::endl;

	if(overflow)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << getDoubleString(d) << std::endl;
}

void convertDoubleSpecial(std::stringstream &stream)
{
	const std::string str = stream.str();

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << (str + "f") << std::endl;
	std::cout << "double: " << str << std::endl;
}

void convertDouble(std::stringstream &stream)
{
	if (isSpecialCase(stream))
	{
		convertDoubleSpecial(stream);
		return;
	}

	double d;
	bool overflow = !(stream >> d);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if(overflow)
		std::cout << "char: impossible" << std::endl;
	else if(d < static_cast<double>(std::numeric_limits<char>::min()) || d > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "char: overflow" << std::endl;
	else if(isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: not displayable" << std::endl;

	if(overflow)
		std::cout << "int: impossible" << std::endl;
	else if(d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	if(overflow)
		std::cout << "float: impossible" << std::endl;
	else if(d < static_cast<double>(std::numeric_limits<float>::lowest()) || d > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << getFloatString(f) << std::endl;

	if(overflow)
		std::cout << "double: overflow" << std::endl;
	else
		std::cout << "double: " << getDoubleString(d) << std::endl;
}

void convertType(std::stringstream &stream, e_type type)
{
	switch(type)
	{
		case CHAR:
			convertChar(stream);
			break;
		case INT:
			convertInt(stream);
			break;
		case FLOAT:
			convertFloat(stream);
			break;
		case DOUBLE:
			convertDouble(stream);
		case INVALID:
			break;
	}
}

int ScalarConverter::convert(const std::string &str)
{
	std::stringstream stream(str);

	e_type type = getType(str);

	if(type == INVALID)
	{
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}

	convertType(stream, type);

	// 2147483647
	// 2147483777

	return 0;
}
