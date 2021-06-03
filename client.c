#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

void send_char(char c, int serv_pid)
{
	int letter;
	int b_let;
	int i;

	letter = c;
	i = 0;
	printf("letter = %d\n", letter);
	while (i < 8)
	{
		b_let = letter % 2;
		letter = letter / 2;
		if (b_let == 1)
			kill(serv_pid, SIGUSR1);
		else if (b_let == 0)
			kill(serv_pid, SIGUSR2);
		usleep(100);
		printf("%d", b_let);
		i++;
	}
	printf("\n_____\n");
}

void str_convert(char *str, int serv_pid)
{
	int i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], serv_pid);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int pid;

	pid = atoi(argv[1]);
	if (argc < 2 || pid < 0)
		return (EXIT_FAILURE);
	str_convert(argv[2], pid);
	return (EXIT_SUCCESS);
}
