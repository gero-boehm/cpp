#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(): _index(0), _max_index(0) {};

PhoneBook::~PhoneBook() {};

std::string PhoneBook::get_input(const std::string prompt)
{
	std::string input;

	while(1)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if(input.length() > 0)
			return input;
	}
}

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

void PhoneBook::add_contact()
{
	std::string first_name = get_input("First Name: ");
	std::string last_name = get_input("Last Name: ");
	std::string nickname = get_input("Nickname: ");
	std::string phone_number = get_input("Phone number: ");
	std::string darkest_secret = get_input("Darkest secret: ");

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
		std::cout << "No contacts available. Run ADD to add contacts." << std::endl;
		return;
	}

	_print_line("Index", "First name", "Last name", "Nickname");

	for(int i = 0; i < _max_index; i++)
		_print_line(std::to_string(i), _contacts[i].get_first_name(), _contacts[i].get_last_name(), _contacts[i].get_nickname());
}