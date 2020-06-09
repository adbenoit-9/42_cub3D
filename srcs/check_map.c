/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:24:17 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 22:51:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_hole(t_game **game, char **map, int i)
{
	int j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == HOLE)
		{
			if (j != 0 && map[i][j - 1] != HOLE && map[i][j - 1] != WALL)
				exit_error(game, NULL, MAP_ERR);
			if (j != ft_strlen(map[i]) - 1 && map[i][j + 1] != HOLE &&
												map[i][j + 1] != WALL)
				exit_error(game, NULL, MAP_ERR);
			if (i != 0 && map[i - 1][j] != HOLE && map[i - 1][j] != WALL)
				exit_error(game, NULL, MAP_ERR);
			if (i < (*game)->map_size - 2 && map[i + 1][j] != HOLE &&
												map[i + 1][j] != WALL)
				exit_error(game, NULL, MAP_ERR);
		}
		j++;
	}
	return (NO_ERR);
}

int			check_map_end(t_game **game, char **map, int i)
{
	int j;

	j = 0;
	if ((*game)->state == END)
	{
		while (map[i - 1][j])
		{
			if (map[i - 1][j] != WALL && map[i - 1][j] != HOLE)
				exit_error(game, NULL, MAP_ERR);
			j++;
		}
		return (NO_ERR);
	}
	if (!((*game)->map = realloc_tab((*game)->map, i + 1)))
		exit_error(game, NULL, MAL_ERR);
	return (NO_ERR);
}

int			check_map_border(t_game **game)
{
	int index[2];
	int size[2];

	if ((*game)->player.start_pos != 1)
		exit_error(game, NULL, MAP_ERR);
	index[X] = 0;
	while ((*game)->map[++index[X]])
	{
		size[1] = ft_strlen((*game)->map[index[X]]);
		size[0] = ft_strlen((*game)->map[index[X] - 1]);
		index[Y] = size[0] > size[1] ? size[1] - 2 : -3;
		while (++index[Y] != -2 && (*game)->map[index[X] - 1][index[Y]])
		{
			if ((*game)->map[index[X] - 1][index[Y]] != WALL &&
			(*game)->map[index[X] - 1][index[Y]] != HOLE)
				exit_error(game, NULL, MAP_ERR);
		}
		index[Y] = size[1] > size[0] ? size[0] - 2 : -3;
		while (++index[Y] != -2 && (*game)->map[index[X]][index[Y]])
		{
			if ((*game)->map[index[X]][index[Y]] != WALL &&
			(*game)->map[index[X]][index[Y]] != HOLE)
				exit_error(game, NULL, MAP_ERR);
		}
		check_hole(game, (*game)->map, index[X]);
	}
	return (NO_ERR);
}
