CC	= g++

SRC	= main.cpp \
	  Parser.cpp

OBJ	= $(SRC:.cpp=.o)

NAME	= ./plazza

FLAG	= -W -Werror -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
