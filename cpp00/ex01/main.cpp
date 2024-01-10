#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone_book;

	try {
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
	} catch(const std::exception &e) {
		std::cout << "Exiting Phonebook." << std::endl;
	}

	return 0;
}

// echo -e "ADD\n0\n0\n0\n0\n0\nADD\n1\n1\n1\n1\n1\nADD\n2\n2\n2\n2\n2\nADD\n3\n3\n3\n3\n3\nADD\n4\n4\n4\n4\n4\nADD\n5\n5\n5\n5\n5\nADD\n6\n6\n6\n6\n6\nADD\n7\n7\n7\n7\n7\nADD\n8\n8\n8\n8\n8\nSEARCH\n0\nEXIT\n" | ./phonebook
