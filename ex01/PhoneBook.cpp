#include "PhoneBook.hpp"

// PhoneBook class methods

void	PhoneBook::addContact(void)
{
	contacts[index].setFirstName(getline("Enter first name: "));
	contacts[index].setLastName(getline("Enter last name: "));
	contacts[index].setNickname(getline("Enter nickname: "));
	contacts[index].setPhoneNumber(getline("Enter phone number: "));
	contacts[index].setDarkestSecret(getline("Enter darkest secret: "));
	index = (index + 1) % 8;
	if (count < 8)
		count++;
	press_enter();
}

void	PhoneBook::searchContact(void)
{
	int	index;

	index = take_index();
	if (index < 0 || index >= count)
	{
		std::cout << RED "Invalid index." RESET << std::endl;
		press_enter();
		return ;
	}
	displayContact(index);
	press_enter();
}

void	PhoneBook::displayContact(int index)
{
	std::cout	<< GREEN "\nFirst name: " << contacts[index].getFirstName() << "\n"
				<< "Last name: " << contacts[index].getLastName() << "\n"
				<< "Nickname: " << contacts[index].getNickname() << "\n"
				<< "Phone number: " << contacts[index].getPhoneNumber() << "\n"
				<< "Darkest secret: " << contacts[index].getDarkestSecret() << "\n\n" RESET;
}

void	PhoneBook::displayAllContacts(void)
{
	if (count == 0)
	{
		std::cout << RED "No contacts to display." RESET << std::endl;
		press_enter();
		return ;
	}
	std::cout	<< "+----------+----------+----------+----------+\n"
				<< "|     Index|First Name| Last Name|  Nickname|\n"
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|"
				  << std::setw(10) << reform_string(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << reform_string(contacts[i].getLastName()) << "|"
				  << std::setw(10) << reform_string(contacts[i].getNickname()) << "|"
				  << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	searchContact();
}

// Utility functions

int	take_index(void)
{
	int	index;

	std::cout << MAGENTA "Enter index of contact to display: " RESET;
	std::cin >> index;
	if (std::cin.eof())
	{
		std::cout << RED "\nProgram terminated by EOF" RESET << std::endl;
		exit(0);
	}
	return (index);
}

void	press_enter(void)
{
	std::cout << "Press Enter to continue...";
	getline("");
	std::cout << std::endl;
}

std::string	reform_string(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

std::string	getline(std::string prompt)
{
	std::string	input;

	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << RED "\nProgram terminated by EOF" RESET << std::endl;
		exit(0);
	}
	return (input);
}
