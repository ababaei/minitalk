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
	send_char('\0', serv_pid);
}

void sig_handler(int signum)
{
	printf("Message bien recu par le serveur.\n");
}

int	main(int argc, char *argv[])
{
	int pid;

	pid = ft_atoi(argv[1]);
	if (argc <= 2 || pid < 0)
		return (EXIT_FAILURE);
	signal(SIGUSR1, sig_handler);
	str_convert(ft_itoa(getpid()), pid); 
	str_convert(argv[2], pid);
	return (EXIT_SUCCESS);
}
