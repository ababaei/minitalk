/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:00:28 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:21:39 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	isinset(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

static int	trimcount(char const *s1, char const *set)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = 0;
	while (isinset(s1[i], set) && *s1)
	{
		i++;
		tmp++;
	}
	i = ft_strlen(s1) - 1;
	while (isinset(s1[i], set) && i >= 0)
	{
		i--;
		tmp++;
	}
	if (tmp >= ft_strlen(s1))
		return (ft_strlen(s1));
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	int unsigned	k;
	int unsigned	tmp;
	char			*str;

	i = 0;
	k = 0;
	tmp = trimcount(s1, set);
	str = malloc(sizeof(char) * ft_strlen(s1) - tmp + 1);
	if (str == NULL)
		return (0);
	if (tmp >= ft_strlen(s1))
	{
		str[0] = '\0';
		return (str);
	}
	while (isinset(s1[i], set) && *s1)
		i++;
	while (k < ft_strlen(s1) - tmp)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
