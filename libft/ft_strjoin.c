/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:35:06 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:11:12 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	t_len;
	size_t			i;
	size_t			j;
	char			*ptr;

	j = 0;
	i = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (t_len + 1));
	if (ptr == NULL)
		return (0);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
