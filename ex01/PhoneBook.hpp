#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

// clors macros
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

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
int			take_index(void);
void		press_enter(void);
std::string	reform_string(std::string str);
std::string	getline(std::string prompt);

#endif
