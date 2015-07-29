/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:47:08 by cjacquem          #+#    #+#             */
/*   Updated: 2015/07/29 13:17:23 by cjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			ft_nb_line(char **tab)
{
	int e;
	int nb;
	int i;

	i = 0;
	e = 0;
	nb = 0;
	nb = ft_atoi(&e,tab[0]);
	if (nb > 0 && nb < 2147483647)
	{
		while (tab[i] != '\0')
			i++;
		if ( i - 1 != nb)
		{
			return (0);
		}
		return(e);
	}
	else
		return (0);
}

int			ft_find_elem(int y, char **str, t_box box)
{
	box.empty = str[0][y];
	box.obstacle = str[0][y + 1];
	box.full = str[0][y+2];
	if ((box.empty == box.obstacle || box.empty == box.full)
			|| box.obstacle == box.full)
		return(0);
	return(1);
}

int			ft_nb_column(char **tab)
{
	int i;

	i = 0;
	while (tab[1][i] != '\0')
		i++;
	return (i);
}

int			ft_check_size_line(char **tab, int y)
{
	int j;
	int i;

	j = 0;
	i = 1;
	while (tab[i] != '\0')
	{
		while (tab[i][j] != '\0')
		{
			j++;
		}
		if (j != y)
		{
			return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int			ft_check(char **tab)
{
	int y;
	t_box box;
	box = *(t_box*)malloc(sizeof(t_box*));
	y = 0;

	y = ft_nb_line(tab);
	if (y == 0)
		return (1);
	y = ft_nb_column(tab);
	if (y == 0)
		return (1);
	y = ft_check_size_line(tab, y);
	if (y == 0)
		return (1);
	y = ft_find_elem(y, tab, box);
	if (y == 0)
		return (1);
	return (0);
}
