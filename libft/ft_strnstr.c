/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:56:45 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:13:11 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
		if (*str2 == '\0')
			return (0);
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		if ((int)n >= (int)(ft_strlen(s2)))
		{
			j = 0;
			if (ft_strcmp((char *)s1 + i, (char *)s2 + j) == 0)
				return ((char *)s1 + i);
		}
		i++;
		n--;
	}
	return (0);
}
