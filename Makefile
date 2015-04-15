##
## Makefile for makefile in /home/durand_u/github/plazza
##
## Made by Rémi DURAND
## Login <durand_u@epitech.net>
##
## Started on Wed Apr 15 09:48:29 2015 Rémi DURAND
## Last update Wed Apr 15 10:56:05 2015 Rémi DURAND
##

SRC	=	plazza.cpp	\
		Parser.cpp	\

CC	=	g++

RM	=	rm -f

OBJ	=	$(SRC:.cpp=.o)

NAME	=	plazza

CXXFLAGS	+= -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
