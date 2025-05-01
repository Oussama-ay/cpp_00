NAME = phonebook
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	PhoneBook.cpp \
		PhoneBook_utils.cpp \
		getters_setters.cpp \
		utils.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
