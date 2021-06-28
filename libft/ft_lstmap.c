/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:56:17 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 17:27:54 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	if (!f || !del)
	{
		while (lst)
		{
			tmp = ft_lstnew(f(lst->content));
			if (tmp == NULL)
			{
				ft_lstclear(&new_list, del);
				return (0);
			}
			ft_lstadd_back(&new_list, tmp);
			lst = lst->next;
		}
	}
	return (new_list);
}
