#include <iostream>
#include <string>

void	str_toupper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	std::cout << str;
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
		str_toupper(av[i]);
	std::cout << std::endl;
	return (0);
}
