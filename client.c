#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_char(char c, int serv_pid)
{
	int	letter;
	int	b_let;
	int	i;

	letter = c;
	i = 0;
	while (i < 8)
	{
		b_let = letter % 2;
		letter = letter / 2;
		if (b_let == 1)
			kill(serv_pid, SIGUSR1);
		else if (b_let == 0)
			kill(serv_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	str_convert(char *str, int serv_pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], serv_pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc <= 2 || argc > 3 || ft_atoi(argv[1]) < 0)
	{
		printf("Error: wrong argument number\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("Error: bad PID\n");
		return (EXIT_FAILURE);
	}
	str_convert(argv[2], ft_atoi(argv[1]));
	return (EXIT_SUCCESS);
}
