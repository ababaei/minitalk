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

void	sig_handler(int signum)
{
	static int	decnum = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
	{
		decnum = decnum + ft_power(2, i);
		i++;
	}
	if (signum == SIGUSR2)
		i++;
	if (i == 8)
	{
		write(1, &decnum, 1);
		i = 0;
		decnum = 0;
		usleep(25);
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
