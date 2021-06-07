#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	ft_power(int nb, int power)
{
	int	n;

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

void	convert_print(char *num)
{
	int	i;
	int	decnum;
	int	p;

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

void	sig_handler(int signum)
{
	static char	buf[9];
	static int	i = 7;

	buf[8] = '\0';
	if (signum == SIGUSR1)
	{
		buf[i] = '1';
		i--;
	}
	if (signum == SIGUSR2)
	{
		buf[i] = '0';
		i--;
	}
	if (i < 0)
	{
		convert_print(buf);
		i = 7;
	}
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	printf("PID = %d\n", getpid());
	while (1)
	{
	}
}
