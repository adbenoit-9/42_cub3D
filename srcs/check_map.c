/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:24:17 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/31 11:25:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_hole(t_all **all, char **map, int i)
{
	int j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == HOLE)
		{
			if (j != 0 && map[i][j - 1] != HOLE && map[i][j - 1] != WALL)
				exit_error(all, NULL, MAP_ERR);
			if (j != ft_strlen(map[i]) - 1 && map[i][j + 1] != HOLE &&
												map[i][j + 1] != WALL)
				exit_error(all, NULL, MAP_ERR);
			if (i != 0 && map[i - 1][j] != HOLE && map[i - 1][j] != WALL)
				exit_error(all, NULL, MAP_ERR);
			if (i != (*all)->map_size - 1 && map[i + 1][j] != HOLE &&
												map[i + 1][j] != WALL)
				exit_error(all, NULL, MAP_ERR);
		}
		j++;
	}
	return (NO_ERR);
}

int			check_map_end(t_all **all, char **map, int i)
{
	int j;

	j = 0;
	if ((*all)->state == END)
	{
		while (map[i - 1][j])
		{
			if (map[i - 1][j] != WALL && map[i - 1][j] != HOLE)
				exit_error(all, NULL, MAP_ERR);
			j++;
		}
		return (NO_ERR);
	}
	if (!((*all)->map = realloc_tab((*all)->map, i + 1)))
		exit_error(all, NULL, MAL_ERR);
	return (NO_ERR);
}

int			check_map_border(t_all **all)
{
	int index[2];
	int size[2];

	if ((*all)->player.start_pos != 1)
		exit_error(all, NULL, MAP_ERR);
	index[X] = 0;
	while ((*all)->map[++index[X]])
	{
		size[1] = ft_strlen((*all)->map[index[X]]);
		size[0] = ft_strlen((*all)->map[index[X] - 1]);
		index[Y] = size[0] > size[1] ? size[1] - 1 : -2;
		while (++index[Y] != -1 && (*all)->map[index[X] - 1][index[Y]])
		{
			if ((*all)->map[index[X] - 1][index[Y]] != WALL)
				exit_error(all, NULL, MAP_ERR);
		}
		index[Y] = size[1] > size[0] ? size[0] - 1 : -2;
		while (++index[Y] != -1 && (*all)->map[index[X]][index[Y]])
		{
			if ((*all)->map[index[X]][index[Y]] != WALL)
				exit_error(all, NULL, MAP_ERR);
		}
		check_hole(all, (*all)->map, index[X]);
	}
	return (NO_ERR);
}
