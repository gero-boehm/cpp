#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone_book;

	while(1)
	{
		std::string input = phone_book.get_input("Enter command: ");

		if(input == "ADD")
			phone_book.add_contact();
		else if(input == "SEARCH")
			phone_book.search_contacts();
		else if(input == "EXIT")
			return 0;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}