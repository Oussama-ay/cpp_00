#ifndef PHONEBOOK   
#define PHONEBOOK

#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <cstdio>
#include <limits>
#include <unistd.h>

// clors macros
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	void		setFirstName(std::string firstName);
	void		setLastName(std::string lastName);
	void		setNickname(std::string nickname);
	void		setPhoneNumber(std::string phoneNumber);
	void		setDarkestSecret(std::string darkestSecret);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
};

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
	int		count;

public:
	PhoneBook() : index(0), count(0) {}
	void	addContact();
	void	searchContact();
	void	displayContact(int index);
	void	displayAllContacts();
};

// Utility functions
std::string	getline(std::string prompt);
std::string	str_tolower(std::string str);
int			take_index(void);
void		press_enter(void);
std::string	reform_string(std::string str);

#endif
