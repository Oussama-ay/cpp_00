#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	system("clear");
	while (true)
	{
		command = getline(YELLOW "Please enter a command (ADD, SEARCH, EXIT): " RESET);
		system("clear");
		if (str_tolower(command) == "add")
			phoneBook.addContact();
		else if (str_tolower(command) == "search")
			phoneBook.displayAllContacts();
		else if (str_tolower(command) == "exit")
			break ;
	}
	std::cout << MAGENTA "Exiting the program." RESET << std::endl;
	return (0);
}
