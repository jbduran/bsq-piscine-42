/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 13:54:06 by cjacquem          #+#    #+#             */
/*   Updated: 2015/07/29 13:04:35 by djean-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define Y_MAP		(*dim)->size[0];
# define X_MAP		(*dim)->size[1];

typedef	struct			s_box
{
	char	empty;
	char	obstacle;
	char	full;
}						t_box;

typedef struct			s_dim
{
	int		size[2];
}						t_dim;

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);

int			ft_atoi(int *pos, char *str);
int			ft_strlen(char *str);
int			ft_count_word(char *tab, int *max);
int			ft_search(char **tab);

char		*ft_strdmp(char *tab, int size);
char		**ft_split_tab(char *tab);
char		**ft_read_file(char *argv);

int			ft_nb_line(char **tab);
int			ft_check(char **tab);
int			ft_find_elem(int y, char **tab, t_box box);
int			ft_nb_column(char **tab);
int			ft_check_size_line(char **tab, int y);
#endif
