#include "Contact.hpp"

Contact::Contact(const std::string first_name, const std::string last_name, const std::string nickname, const std::string phone_number, const std::string darkest_secret): _first_name(first_name), _last_name(last_name), _nickname(nickname), _phone_number(phone_number), _darkest_secret(darkest_secret) {};

Contact::Contact() {};

Contact::~Contact() {};

std::string Contact::get_first_name() const
{
	return _first_name;
}

std::string Contact::get_last_name() const
{
	return _last_name;
}

std::string Contact::get_nickname() const
{
	return _nickname;
}
