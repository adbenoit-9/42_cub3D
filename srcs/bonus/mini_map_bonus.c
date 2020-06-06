/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:18:04 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:07:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	max_len(t_all **all)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while ((*all)->map[i])
	{
		if (ft_strlen((*all)->map[i]) > max)
			max = ft_strlen((*all)->map[i]);
		i++;
	}
	return (max);
}

static void	draw_square(t_all **all, int *j, int *i, int *index)
{
	int k;
	int col;
	int	x;
	int	y;

	k = 0;
	x = index[X];
	y = index[Y];
	while (k < (*all)->bonus.mm_dim)
	{
		if ((*all)->map[x][y] == WALL || (*all)->map[x][y] == DOOR)
		{
			col = (*all)->img.data[*j + (*all)->r[X] * *i];
			(*all)->img.data[*i + (*all)->r[X] * *j] = ft_rgb(151, 153, 131);
		}
		if (y == (int)(*all)->player.pos[X] && x == (int)(*all)->player.pos[Y])
			(*all)->img.data[*i + (*all)->r[X] * *j] = ft_rgb(33, 81, 116);
		if ((*all)->map[x][y] == OBJ1)
			(*all)->img.data[*i + (*all)->r[X] * *j] = ft_rgb(213, 84, 84);
		k++;
		(*i)++;
	}
}

void		draw_mini_map(t_all **all)
{
	int start[2];
	int k;
	int k1;
	int index[2];

	start[Y] = 0;
	k1 = ((*all)->r[Y] / (*all)->map_size) / 6;
	k = ((*all)->r[X] / max_len(all)) / 6;
	(*all)->bonus.mm_dim = k1 > k ? k : k1;
	index[X] = 0;
	while ((*all)->map[index[X]])
	{
		k = 0;
		while (k < (*all)->bonus.mm_dim)
		{
			index[Y] = -1;
			start[X] = 0;
			while ((*all)->map[index[X]][++index[Y]])
				draw_square(all, &start[Y], &start[X], index);
			start[Y]++;
			k++;
		}
		index[X]++;
	}
}
