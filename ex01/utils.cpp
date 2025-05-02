#include "PhoneBook.hpp"

std::string	str_tolower(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
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
