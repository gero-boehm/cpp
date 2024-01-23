#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <stdexcept>

struct Date
{
	int index;
	long timestamp;
	std::string str;
	bool valid;

	Date(int index, long timestamp, const std::string &str, bool valid);

	static Date invalid(int index, const std::string &str);
	static int daysInMonth(int year, int month);
	static bool isLeapYear(int year);
	static long getTimestamp(int year, int month, int day);
	static const Date parse(int index, const std::string &str);

	bool operator<(const Date &other) const;
};

struct Value
{
	float value;
	bool valid;

	Value(float value, bool valid);

	static const Value parse(const std::string &str);
};

class BitcoinExchange
{
	private:
		BitcoinExchange(void);
		const std::map<Date, Value> _database;
		const std::map<Date, Value> _input;

		static const std::map<Date, Value> parse(const std::string &fspath, const std::string &delim);

	public:
		BitcoinExchange(const std::string &database, const std::string &input);
		BitcoinExchange(const BitcoinExchange &bitcoinExchange);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);
		~BitcoinExchange();

		bool isDatabaseInvalid(void) const;

		void calculate(void) const;
		std::map<Date, Value>::const_reverse_iterator getMatch(const Date &date) const;

		class DatabaseInvalid: public std::exception
		{
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const Date &date);
std::ostream &operator<<(std::ostream &out, const Value &value);

#endif
