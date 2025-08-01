#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>

// colors macros
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
	void	searchContact();
	void	displayContact(int index);

public:
	PhoneBook() : index(0), count(0) {}
	void	addContact();
	void	displayAllContacts();
};

// Utility functions
int			take_index(void);
std::string	reform_string(std::string str);
std::string	getline();
void		cout(std::string str);

#endif
