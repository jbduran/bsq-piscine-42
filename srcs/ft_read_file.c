/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean-ba <djean-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 18:27:44 by djean-ba          #+#    #+#             */
/*   Updated: 2015/07/28 21:56:38 by djean-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdmp(char *tab, int size)
{
	char	*tab2;
	int		n;

	n = 0;
	while (tab[n])
		n++;
	tab2 = malloc((size + 1) * sizeof(char));
	n = 0;
	while (tab[n])
	{
		tab2[n] = tab[n];
		n++;
	}
	free(tab);
	return (tab2);
}

int		ft_count_word(char *tab, int *max)
{
	int	i;
	int	n;
	int	c;

	*max = 0;
	n = 0;
	c = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
		{
			n++;
			c = 0;
		}
		else
			c++;
		if (c > *max)
			*max = c;
		i++;
	}
	return (n);
}

char	**ft_split_tab(char *tab)
{
	char	**tab2;
	int		c[3];
	int		max;

	c[2] = ft_count_word(tab, &max);
	c[0] = 0;
	tab2 = malloc((c[2] + 2) * sizeof(char *));
	while (c[0] < c[2] + 1)
		tab2[c[0]++] = malloc((max + 1) * sizeof(char));
	c[0] = -1;
	c[1] = 0;
	c[2] = 0;
	while (tab[++c[0]])
		if (tab[c[0]] == '\n')
		{
			tab2[c[1]++][c[2]] = '\0';
			c[2] = 0;
		}
		else
			tab2[c[1]][c[2]++] = tab[c[0]];
	tab2[c[1] + 1] = 0;
	return (tab2);
}

char	**ft_read_file(char *argv)
{
	char	*tab;
	char	buf[1];
	int		i;
	int		size;
	int		fd;
	size = 1;
	i = 0;
	tab = malloc(2 * sizeof(char));
	fd = open(argv, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (i >= size)
		{
			tab[i] = '\0';
			size = size * 2;
			tab = ft_strdmp(tab, size);
		}
			tab[i] = buf[0];
			i++;
	}
	tab[i - 1] = '\0';
	close(fd);
	{
	}
	return (ft_split_tab(tab));
}
