/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:20:53 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:04:17 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_putnbr_fd(int n, int fd, int printed)
{
	long	tmp;
	char	min;

	min = '-';
	tmp = n;
	if (tmp < 0)
	{
		printed += 1;
		write(fd, &min, 1);
		tmp = -tmp;
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd, printed++);
	}
	tmp = (tmp % 10) + '0';
	write(fd, &tmp, 1);
	return (printed++);
}
