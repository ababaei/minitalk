/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:21:37 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:22:21 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_sizecount(int n, int *pt_neg)
{
	int	tmp;

	tmp = 0;
	if (n < 0)
	{
		*pt_neg = 1;
		tmp++;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		tmp++;
	}
	return (tmp);
}

static char	*ft_strrev(char *str, int neg, int size)
{
	int		i;
	int		j;
	char	tmp;

	i = size - 1;
	j = neg;
	while (j < size / 2 + neg)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i--;
		j++;
	}
	return (str);
}

static char	*ft_strfill(char *str, int n, int neg)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	if (neg)
	{
		str[i] = '-';
		i++;
		tmp = -n;
	}
	else
		tmp = n;
	while (tmp)
	{
		str[i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (n == 0)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		size;
	char	*f_str;

	neg = 0;
	size = ft_sizecount(n, &neg);
	f_str = malloc(sizeof(char) * (size + 1));
	if (f_str == NULL)
		return (0);
	f_str = ft_strfill(f_str, n, neg);
	f_str = ft_strrev(f_str, neg, size);
	return (f_str);
}
