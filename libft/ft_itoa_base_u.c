/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:49:58 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 17:37:12 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	convert_len(uintmax_t i, int baselen)
{
	int	len;

	len = 0;
	while (i)
	{
		i /= baselen;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_u(uintmax_t nb, char *base)
{
	uintmax_t	tmp;
	int			len;
	int			baselen;
	char		*ret;

	tmp = ft_abs(nb);
	baselen = ft_strlen(base);
	len = convert_len(nb, baselen);
	if (tmp == 0)
		len = 1;
	ret = malloc(sizeof(char) * (len + 1));
	ret[len] = '\0';
	len--;
	while (len >= 0)
	{
		ret[len] = base[tmp % baselen];
		tmp = tmp / baselen;
		len--;
	}
	return (ret);
}
