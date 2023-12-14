#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact _contacts[MAX_CONTACTS];
		int _index;
		int _max_index;

		void _print_line(const std::string str1, const std::string str2, const std::string str3, const std::string str4);
		std::string _truncate_str(std::string str);

	public:
		PhoneBook();
		~PhoneBook();

		std::string get_input(std::string prompt);
		void add_contact();
		void search_contacts();

};

#endif