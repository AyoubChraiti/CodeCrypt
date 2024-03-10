SRC = main.c input_handl.c utils.c

INCLUDE = libft.a

NAME = ex

CC = cc

all:
	$(CC) $(SRC) $(INCLUDE) -o $(NAME)

fclean:
	rm -rf $(NAME)
