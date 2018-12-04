/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:50:33 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/04 22:06:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdio.h>
/*
** format_check() allows to validate the input file and it retruns number
** of pieces
** It checks:
**	- line length
**	- tetri separate by 1 line
**	- only 4 # per tetri
*/

unsigned int		bloc_cnt(char *buff)
{
	unsigned int	i;
	unsigned int	bloc_cnt;
	
	i = 0;
	bloc_cnt = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
		{
			if (buff[i] != '\n')
				return (0);
		}
		else if (buff[i] != '.' && buff[i] != '#')
			return (0);
		if (buff[i] == '#')
			bloc_cnt++;
		i++;
	}
	if (bloc_cnt != 4)
		return (0);
	return (1);
}


unsigned int		format_check(int fd)
{
	unsigned int	tetri_cnt;

	char			buff[21];
	int				y;

	tetri_cnt = 0;
	while ((y = read(fd, buff, 21)))
	{
		if (y == 20)
		{
			if(!bloc_cnt(buff))
				return (0);
			tetri_cnt++;
			break ;
		}
		if (buff[20] != '\n')
			return (0);
		if(!bloc_cnt(buff))
			return (0);
		tetri_cnt++;
	}
	if (y == 20)
		return (tetri_cnt);
	return (0);
}

/*
** Check tetriminos shapes
** by counting the number of touching sides
*/

int					isvalid_tetri(char *tetri)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
			i++;
		if (tetri[i] == '#')
		{
			if (i < 19 && tetri[i + 1] == '#')
				count++;
			if (i < 14 && tetri[i + 5] == '#')
				count++;
			if (i > 0 && tetri[i - 1] == '#')
				count++;
			if (i > 4 && tetri[i - 5] == '#')
				count++;
		}
		i++;	
	}
	if (count < 6)
		return (0);
	return (1);
}

unsigned int		pieces_check(int fd, int tetri_cnt)
{
	unsigned		i;
	t_tetri_coo		*tab;
	char			buff[21];

	if (!(tab = (t_tetri_coo *)malloc(sizeof(t_tetri_coo) * tetri_cnt)))
	{
		ft_putendl_fd("error: while malloc tab", 1);
		return (1);
	}
	i = 0;
	while (read(fd, buff, 21) > 0)
	{
		if (!isvalid_tetri(buff))
			return (0);
		tab[i] = fill_tetri_coo(buff);
		i++;
	}
	printf("x=%d y=%d\n\n", tab[2].p0.x, tab[2].p0.y);
	printf("x=%d y=%d\n\n", tab[2].p1.x, tab[2].p1.y);
	printf("x=%d y=%d\n\n", tab[2].p2.x, tab[2].p2.y);
	printf("x=%d y=%d\n\n", tab[2].p3.x, tab[2].p3.y);
	return (1);
}
