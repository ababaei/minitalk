#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

int	ft_power(int nb, int power)
{
	int n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		n *= nb;
		power--;
	}
	return (n);
}

void convert_print(char *num)
{
	int i;
	int decnum;
	int p;

	i = 0;
	decnum = 0;
	p = 7;
	while (num[i])
	{
		if (num[i] == '1')
			decnum = decnum + ft_power(2, p);
		i++;
		p--;
	}
	write(1, &decnum, 1);
}

void sig_handler(int signum)
{
	static char buf[9];
	static int i = 7;

	buf[8] = '\0';
	if (signum == SIGUSR1)
	{
		buf[i] = '1'; 
		i--;
		//write(1, "1", 1);
	}
	if (signum == SIGUSR2)
	{
		buf[i] = '0';
		i--;
		//write(1, "0", 1);
	}
	if (i < 0)
	{
		convert_print(buf);
		//write(1, buf, 8);
		//write(1, "\n", 1);
		i = 7;
	}
}

int main(int argc, char *argv[])
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	printf("PID = %d\n", getpid());
	while(1)
	{

	}
}
