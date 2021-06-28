/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:59:43 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 16:03:15 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	unsigned char	*ptr;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	ptr = 0;
	while (n-- && ptr == 0)
	{
		*(ptr_dest) = *(ptr_src);
		if (*ptr_src == (unsigned char)c)
		{
			ptr = ptr_dest + 1;
		}
		ptr_dest++;
		ptr_src++;
	}
	return (ptr);
}
