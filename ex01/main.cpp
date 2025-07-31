#include "PhoneBook.hpp"

bool error = false;

std::string	getline()
{
	std::string	input;

	if (!error)
		std::getline(std::cin, input);
	if (!error && std::cin.eof())
	{
		cout(RED "\nProgram terminated by EOF\n" RESET);
		error = true;
	}
	return (input);
}

void	cout(std::string str)
{
	if (!error)
		std::cout << str;
}

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	system("clear");
	while (true)
	{
		cout(YELLOW "Please enter a command (ADD, SEARCH, EXIT): " RESET);
		command = getline();
		system("clear");
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.displayAllContacts();
		else if (command == "EXIT")
			break ;
		else
			cout(RED "Invalid command. Please try again.\n" RESET);
		if (error)
			break ;
	}
	std::cout << MAGENTA "Exiting the program.\n" RESET;
	return (0);
}
