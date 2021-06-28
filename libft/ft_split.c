/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:04:41 by ababaei           #+#    #+#             */
/*   Updated: 2021/06/23 17:14:25 by ababaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_wordcount(char const *s, char c)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i])
			tmp++;
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (tmp);
}

static int	ft_wordalloc(char const *s, char c, char **tab)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		tmp = 0;
		if (s[i])
			j++;
		while (s[i] != c && s[++i])
		{
			tmp++;
		}
		if (tmp)
		{
			tab[j] = malloc(sizeof(char) * (tmp + 1));
			if (tab[j] == NULL)
				return (j);
		}
	}
	return (-1);
}

static char	**ft_tabfill(char const *s, char c, char **tab, int wc)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (s[i] && j < wc)
	{
		while (s[i] == c && s[i])
			i++;
		tmp = 0;
		if (s[i])
			j++;
		while (s[i] != c && s[i])
		{
			tab[j][tmp] = s[i];
			i++;
			tmp++;
		}
		if (j < wc && tmp)
			tab[j][tmp] = '\0';
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**f_tab;
	int		wordc;
	int		walloc;

	wordc = ft_wordcount(s, c);
	f_tab = malloc(sizeof(char *) * (wordc + 1));
	if (f_tab == NULL)
		return (0);
	f_tab[wordc] = NULL;
	walloc = ft_wordalloc(s, c, f_tab);
	if (walloc != -1)
	{
		while (walloc >= 0)
		{
			free(f_tab[walloc--]);
		}
		free(f_tab);
		return (0);
	}
	f_tab = ft_tabfill(s, c, f_tab, wordc);
	return (f_tab);
}
