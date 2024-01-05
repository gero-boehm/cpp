#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

typedef struct s_components
{
	int decimal_point;
	int numbers;
	int signs;
	int characters;
} t_components;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarConverter);
		ScalarConverter &operator=(const ScalarConverter &scalarConverter);

	public:
		~ScalarConverter();

		static int convert(const std::string &str);
};

#endif
