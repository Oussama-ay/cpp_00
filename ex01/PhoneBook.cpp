#include "PhoneBook.hpp"

extern bool error;
bool	is_empty(std::string &str);
std::string	take_input(bool is_nbr);

// PhoneBook class methods

void	PhoneBook::addContact(void)
{
	cout("Enter first name: ");
	contacts[index].setFirstName(take_input(false));
	cout("Enter last name: ");
	contacts[index].setLastName(take_input(false));
	cout("Enter nickname: ");
	contacts[index].setNickname(take_input(false));
	cout("Enter phone number: ");
	contacts[index].setPhoneNumber(take_input(true));
	cout("Enter darkest secret: ");
	contacts[index].setDarkestSecret(take_input(false));
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

int	my_stoi(std::string str)
{
	int	result = 0, i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!str[i])
		return (-1);
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

std::string	take_input(bool is_nbr)
{
	std::string	res;
	std::string	tmp;
	int			nbr;
	bool		flag;

	nbr = 0;
	do
	{
		res = getline();
		if (is_nbr)
			nbr = my_stoi(res);
		flag = is_empty(res);
		if (flag || nbr == -1)
			cout(RED "Invalid input, Retry: " RESET);
	}	while ((flag || nbr == -1) && !error);
	return (res);
}

bool	is_empty(std::string &str)
{
	int i = 0;
	while (str[i] && std::isspace(str[i]))
		i++;
	if (str[i])
		return (false);
	return (true);
}
