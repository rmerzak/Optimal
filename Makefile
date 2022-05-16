NAME = optimal

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = optimal.h

SRC = ./main.c\
	  ./utile.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
