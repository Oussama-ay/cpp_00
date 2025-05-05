#include "PhoneBook.hpp"

static void	str_tolower(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	system("clear");
	while (true)
	{
		command = getline(YELLOW "Please enter a command (ADD, SEARCH, EXIT): " RESET);
		str_tolower(command);
		system("clear");
		if (command == "add")
			phoneBook.addContact();
		else if (command == "search")
			phoneBook.displayAllContacts();
		else if (command == "exit")
			break ;
	}
	std::cout << MAGENTA "Exiting the program." RESET << std::endl;
	return (0);
}
