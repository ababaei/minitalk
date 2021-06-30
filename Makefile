CC = gcc

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

FLAGS = -Wall -Wextra -Werror
NAME = minitalk

all:LIBFT SERVER CLIENT

LIBFT:
	make -C libft/

CLIENT:$(OBJ_CLIENT) 
	$(CC) $(OBJ_CLIENT) $(FLAGS) -Llibft/ -lft -o client

SERVER:$(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) $(FLAGS) -Llibft/ -lft -o server

clean:
	rm -f *.o 

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re LIBFT
