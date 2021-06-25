CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = minitalk

all: $(NAME)

LIBFT:
	make -C libft/

$(NAME): LIBFT
	$(CC) $(FLAGS) -Llibft/ -lft -o client client.c
	$(CC) $(FLAGS) -Llibft/ -lft -o server server.c 

bonus:
	$(CC) $(FLAGS) -Llibft/ -lft -o client client_bonus.c
	$(CC) $(FLAGS) -Llibft/ -lft -o server server_bonus.c

clean:
	rm -f *.o 

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
