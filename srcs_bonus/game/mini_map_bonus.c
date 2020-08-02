/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:18:04 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 23:05:02 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	max_len(t_game **game)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while ((*game)->map[i])
	{
		if (ft_strlen((*game)->map[i]) > max)
			max = ft_strlen((*game)->map[i]);
		i++;
	}
	return (max);
}

static void	draw_square(t_game **game, int *j, int *i, int *index)
{
	int k;
	int col;
	int	x;
	int	y;

	k = 0;
	x = index[X];
	y = index[Y];
	while (k < (*game)->mm_dim)
	{
		if ((*game)->map[x][y] == WALL || (*game)->map[x][y] == DOOR)
		{
			col = (*game)->img.data[*j + (*game)->r[X] * *i];
			(*game)->img.data[*i + (*game)->r[X] * *j] = ft_rgb(151, 153, 131);
		}
		if (y == (int)(*game)->player.pos[X] &&
		x == (int)(*game)->player.pos[Y])
			(*game)->img.data[*i + (*game)->r[X] * *j] = ft_rgb(33, 81, 116);
		if ((*game)->map[x][y] == OBJ1)
			(*game)->img.data[*i + (*game)->r[X] * *j] = ft_rgb(213, 84, 84);
		k++;
		(*i)++;
	}
}

void		draw_mini_map(t_game **game)
{
	int start[2];
	int k;
	int k1;
	int index[2];

	start[Y] = 0;
	k1 = ((*game)->r[Y] / (*game)->map_size) / 6;
	k = ((*game)->r[X] / max_len(game)) / 6;
	(*game)->mm_dim = k1 > k ? k : k1;
	index[X] = 0;
	while ((*game)->map[index[X]])
	{
		k = 0;
		while (k < (*game)->mm_dim)
		{
			index[Y] = -1;
			start[X] = 0;
			while ((*game)->map[index[X]][++index[Y]])
				draw_square(game, &start[Y], &start[X], index);
			start[Y]++;
			k++;
		}
		index[X]++;
	}
}
