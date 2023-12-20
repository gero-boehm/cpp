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

enum e_flag
{
	FLAG_NONE = 0,
	FLAG_OVERFLOW = 1,
	FLAG_IMPOSSIBLE = 2,
	FLAG_NAN = 4,
	FLAG_INF = 8,
	FLAG_INF_POSITIVE = 16,
	FLAG_INF_NEGATIVE = 32
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
