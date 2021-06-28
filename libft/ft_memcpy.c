/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:54:59 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:19:12 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;

	if (!dest && !src)
		return (0);
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	while (n--)
	{
		*ptr_dest = *ptr_src;
		ptr_src++;
		ptr_dest++;
	}
	return (dest);
}
