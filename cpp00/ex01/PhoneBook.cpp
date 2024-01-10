#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(): _index(0), _max_index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::_print_line(const std::string str1, const std::string str2, const std::string str3, const std::string str4)
{
	std::cout << std::setw(10) << _truncate_str(str1) << '|';
	std::cout << std::setw(10) << _truncate_str(str2) << '|';
	std::cout << std::setw(10) << _truncate_str(str3) << '|';
	std::cout << std::setw(10) << _truncate_str(str4) << std::endl;
}

std::string PhoneBook::_truncate_str(std::string str)
{
	if(str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return str;
}

std::string PhoneBook::get_input(const std::string prompt)
{
	std::string input;

	while(1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			throw std::exception();
		if(input.length() > 0)
			return input;
	}
}

void PhoneBook::add_contact()
{
	std::string first_name = get_input("First Name: ");
	std::string last_name = get_input("Last Name: ");
	std::string nickname = get_input("Nickname: ");
	std::string phone_number = get_input("Phone Number: ");
	std::string darkest_secret = get_input("Darkest Secret: ");

	_contacts[_index] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);

	_index++;
	if(_index > _max_index)
		_max_index = _index;
	_index %= MAX_CONTACTS;
}

void PhoneBook::search_contacts()
{
	if(_max_index == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return;
	}

	_print_line("Index", "First Name", "Last Name", "Nickname");

	for(int i = 0; i < _max_index; i++)
	{
		std::ostringstream stream;
		stream << i;
		_print_line(stream.str(), _contacts[i].get_first_name(), _contacts[i].get_last_name(), _contacts[i].get_nickname());
	}

	while (1)
	{
		std::string str = get_input("Enter index: ");

		int index;
		std::istringstream stream(str);

		if(!(stream >> index) || index < 0 || index >= _max_index || !stream.eof())
		{
			std::cout << "Invalid index." << std::endl;
			continue;
		}
		_contacts[index].print();
		break;
	}
}
