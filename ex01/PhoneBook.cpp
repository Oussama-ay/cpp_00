#include "PhoneBook.hpp"

extern bool error;
bool	is_valide(std::string &str);

// PhoneBook class methods

void	PhoneBook::addContact(void)
{
	std::string	nbr;
	bool		flag;

	cout("Enter first name: ");
	contacts[index].setFirstName(getline());
	cout("Enter last name: ");
	contacts[index].setLastName(getline());
	cout("Enter nickname: ");
	contacts[index].setNickname(getline());
	do 
	{
		cout("Enter phone number: ");
		nbr = getline();
		flag = is_valide(nbr);
		if (!flag)
			cout(RED "Invalid number.\n" RESET);
	} while (!flag);
	contacts[index].setPhoneNumber(nbr);
	cout("Enter darkest secret: ");
	contacts[index].setDarkestSecret(getline());
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

void	PhoneBook::searchContact(void)
{
	int	index;

	index = take_index();
	if (index < 0 || index >= count)
	{
		cout(RED "Invalid index.\n" RESET);
		return ;
	}
	displayContact(index);
}

void	PhoneBook::displayContact(int index)
{
	if (!error)
	{	
		std::cout	<< GREEN "\nFirst name: " << contacts[index].getFirstName() << "\n"
					<< "Last name: " << contacts[index].getLastName() << "\n"
					<< "Nickname: " << contacts[index].getNickname() << "\n"
					<< "Phone number: " << contacts[index].getPhoneNumber() << "\n"
					<< "Darkest secret: " << contacts[index].getDarkestSecret() << "\n\n" RESET;
	}
}

void	PhoneBook::displayAllContacts(void)
{
	if (count == 0)
	{
		cout(RED "No contacts to display.\n" RESET);
		return ;
	}
	cout("+----------+----------+----------+----------+\n"
		 "|     Index|First Name| Last Name|  Nickname|\n"
		 "+----------+----------+----------+----------+\n");
	for (int i = 0; !error && i < count; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|"
				  << std::setw(10) << reform_string(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << reform_string(contacts[i].getLastName()) << "|"
				  << std::setw(10) << reform_string(contacts[i].getNickname()) << "|"
				  << std::endl;
	}
	cout("+----------+----------+----------+----------+\n");
	searchContact();
}

// Utility functions

bool is_valide(std::string &str)
{
	int i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (false);
	return (true);
}

int	my_stoi(std::string str)
{
	int	result = 0, i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	return (result);
}

int	take_index(void)
{
	int			index;
	std::string input;

	cout(MAGENTA "Enter index of contact to display: " RESET);
	input = getline();
	index = my_stoi(input);
	return (index);
}

std::string	reform_string(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
