/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:19:25 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:16:41 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	tmp;
	int	neg;

	neg = 1;
	tmp = 0;
	while (*nptr && (*nptr == ' '
			|| (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr && *nptr <= '9' && *nptr >= '0')
	{
		tmp = tmp * 10 + (*nptr - 48);
		nptr++;
	}
	return (tmp * neg);
}
