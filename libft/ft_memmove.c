/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:11:26 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:03:31 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;

	if (!dest && !src && n)
		return (0);
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	if (ptr_src < ptr_dest)
	{
		ptr_dest = ptr_dest + n;
		ptr_src = ptr_src + n;
		while (n--)
			*(--ptr_dest) = *(--ptr_src);
	}
	else
	{
		while (n--)
			*(ptr_dest++) = *(ptr_src++);
	}
	return (dest);
}
