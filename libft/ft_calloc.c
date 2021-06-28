/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:07:34 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:20:18 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (0);
	while (i < (nmemb * size))
	{
		*(tmp + i) = 0;
		i++;
	}
	return (tmp);
}
