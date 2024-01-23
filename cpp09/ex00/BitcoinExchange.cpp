#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string &database, const std::string &input): _database(BitcoinExchange::parse(database, ",")), _input(BitcoinExchange::parse(input, " | "))
{
	if(isDatabaseInvalid())
		throw BitcoinExchange::DatabaseInvalid();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange): _database(bitcoinExchange._database), _input(bitcoinExchange._input) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange)
{
	if(this == &bitcoinExchange)
		return *this;

	const_cast<std::map<Date, Value>&>(_database) = bitcoinExchange._database;
	const_cast<std::map<Date, Value>&>(_input) = bitcoinExchange._input;

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isDatabaseInvalid(void) const
{
	for (std::map<Date, Value>::const_iterator it = _database.begin(); it != _database.end(); it++) {
		const Date &date = it->first;
		const Value &value = it->second;

		if (!date.valid || !value.valid || value.value < 0)
			return true;
	}

	return false;
}

const std::map<Date, Value> BitcoinExchange::parse(const std::string &fspath, const std::string &delim)
{
	std::ifstream file(fspath.c_str());

	std::ostringstream stream;
	stream << "'" << fspath << "': ";

	if(!file.is_open())
	{
		stream << "Unable to open file";
		throw std::runtime_error(stream.str());
	}
	// if (file.tellg() == 0)
	// {
	// 	stream << "File is empty";
	// 	throw std::runtime_error(stream.str());
	// }

	std::string line;
	std::getline(file, line);

	std::map<Date, Value> map;

	for(int i = 0; std::getline(file, line); i++)
	{

		std::string::size_type pos = 0;

		if((pos = line.find(delim)) == std::string::npos)
		{
			Date date = Date::invalid(i, "");
			Value value = Value(0, false);

			map.insert(std::make_pair(date, value));

			continue;
		}

		std::string::size_type end = pos + delim.length();
		std::string dateStr = line.substr(0, pos);
		std::string valueStr = line.substr(end, line.length() - end);

		Date date = Date::parse(i, dateStr);
		Value value = Value::parse(valueStr);

		map.insert(std::make_pair(date, value));
	}

	return map;
}

void BitcoinExchange::calculate(void) const
{
	for (std::map<Date, Value>::const_iterator it = _input.begin(); it != _input.end(); it++)
	{
        const Date &date = it->first;
        const Value &value = it->second;

        if (!date.valid || !value.valid)
		{
			std::cout << "Error: bad input" << std::endl;
			continue;
		}
		if(value.value < 0)
		{
			std::cout << "Error: negative number" << std::endl;
			continue;
		}
		if(value.value > 1000)
		{
			std::cout << "Error: number too large" << std::endl;
			continue;
		}

		std::map<Date, Value>::const_reverse_iterator match = getMatch(date);

		if(match == _database.rend())
		{
			std::cout << "Error: no entry found" << std::endl;
			continue;
		}

		float total = match->second.value * value.value;

		std::cout << match->first << " | " << std::fixed << std::setprecision(2) << total << std::endl;
    }
}

std::map<Date, Value>::const_reverse_iterator BitcoinExchange::getMatch(const Date &date) const
{
	for (std::map<Date, Value>::const_reverse_iterator it = _database.rbegin(); it != _database.rend(); it++)
	{
		Date key = it->first;

		if(key.timestamp <= date.timestamp)
			return it;
	}

	return _database.rend();
}

const char *BitcoinExchange::DatabaseInvalid::what() const throw()
{
	return "Database invalid";
}

// Date stuff
Date::Date(int index, long timestamp, const std::string &str, bool valid): index(index), timestamp(timestamp), str(str), valid(valid) {}

bool Date::isLeapYear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int Date::daysInMonth(int year, int month)
{
	static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && Date::isLeapYear(year))
		return 29;

	return days[month - 1];
}

long Date::getTimestamp(int year, int month, int day)
{
	long days = 0;

	for(int i = 1970; i < year; i++)
		days += Date::isLeapYear(i) ? 366 : 365;

	for(int i = 1; i < month; i++)
		days += Date::daysInMonth(year, i);

	days += day - 1;

	return days * 60 * 60 * 24;
}

Date Date::invalid(int index, const std::string &str)
{
	return Date(index, 0, str, false);
}

const Date Date::parse(int index, const std::string &str)
{
	int year;
	int month;
	int day;
	char dash;

	std::istringstream stream(str);

	if (!(stream >> year) || !(stream >> dash) || dash != '-' || !(stream >> month) || !(stream >> dash) || dash != '-' || !(stream >> day) || !stream.eof())
		return Date::invalid(index, str);

	if(month < 1 || month > 12 || day < 1 || day > Date::daysInMonth(year, month))
		return Date::invalid(index, str);

	long timestamp = Date::getTimestamp(year, month, day);

	return Date(index, timestamp, str, true);
}

bool Date::operator<(const Date &other) const
{
	return index < other.index;
}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
	if(date.valid)
		out << date.str;
	else
		out << "invalid";

	return out;
}

// Value stuff
Value::Value(float value, bool valid): value(value), valid(valid) {}

const Value Value::parse(const std::string &str)
{
	std::istringstream stream(str);
	float f;

	if(!(stream >> f) || !stream.eof())
		return Value(0, false);

	return Value(f, true);
}

std::ostream &operator<<(std::ostream &out, const Value &value)
{
	if(value.valid)
		out << std::fixed << std::setprecision(2) << value.value;
	else
		out << "invalid";

	return out;
}
