/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:55:42 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/07 19:36:35 by penzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include <stdio.h>//tejme

unsigned	ft_sqrt_up(unsigned n)//n = tetri_cnt * 4
{
	unsigned	res;

	res = 0;
	while (res * res < n)
		res++;
	return (res);
}

/*
** create or recreate table
*/

char	**create_square(unsigned length)
{
	//unsigned	starting_size;
	char		**tab;
	unsigned	i;

	//starting_size = ft_sqrt_up(nb_tetri * 4);
	if (!(tab = (char**)malloc(sizeof(char*) * length)))
		return (NULL);
	i = -1;
	while (++i < length)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * length)))
		{
			while (i-- > 0)
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			free(tab);
			tab = NULL;
			return (NULL);
		}
	}
	fill_w_point(&tab, length);
	return (tab);
}

char	**resize_square(char **tab, unsigned length)
{
	free(tab);
	create_square(length + 1);
	return (tab);
}

void	fill_w_point(char ***tab, unsigned length)
{
	unsigned	x;
	unsigned	y;

	y = -1;
	while (++y < length)
	{
		x = -1;
		while (++x < length)
			tab[0][y][x] = '.';
	}
	return ;
}

//create_square(ft_sqrt_up(nb_tetri * 4);
