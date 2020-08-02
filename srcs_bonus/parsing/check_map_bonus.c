/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:24:17 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:27:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_left(t_game **game, char **map, int i, int j)
{
	int size;

	size = ft_strlen(map[i]);
	if (j != 0 && i != 0 && map[i - 1][j - 1] != HOLE &&
	map[i - 1][j - 1] != WALL && map[i - 1][j - 1] != 0)
		exit_error(game, NULL, MAP_ERR);
	if (i != 0 && map[i - 1][j] != HOLE && map[i - 1][j] != WALL &&
	map[i - 1][j] != 0)
		exit_error(game, NULL, MAP_ERR);
	if (j != 0 && map[i][j - 1] != HOLE && map[i][j - 1] != WALL)
		exit_error(game, NULL, MAP_ERR);
	if (j != 0 && i < (*game)->map_size - 1 && map[i + 1][j - 1] != HOLE
	&& map[i + 1][j - 1] != WALL)
		exit_error(game, NULL, MAP_ERR);
}

static void	check_right(t_game **game, char **map, int i, int j)
{
	int size;

	size = ft_strlen(map[i]);
	if (j != size - 1 && map[i][j + 1] != HOLE && map[i][j + 1] != WALL)
		exit_error(game, NULL, MAP_ERR);
	if (i < (*game)->map_size - 1 && map[i + 1][j] != HOLE &&
	map[i + 1][j] != WALL && map[i + 1][j] != 0)
		exit_error(game, NULL, MAP_ERR);
	if (i < (*game)->map_size - 1 && j != size - 1 && map[i + 1][j + 1]
	!= HOLE && map[i + 1][j + 1] != WALL && map[i + 1][j + 1] != 0)
		exit_error(game, NULL, MAP_ERR);
	if (j != size - 1 && i != 0 && map[i - 1][j + 1] != HOLE &&
	map[i - 1][j + 1] != WALL && map[i - 1][j + 1] != 0)
		exit_error(game, NULL, MAP_ERR);
}

static void	check_border(t_game **game, int x, int y, int n)
{
	while (x < n && (*game)->map[y][x])
	{
		if ((*game)->map[y][x] != WALL && (*game)->map[y][x] != HOLE)
			exit_error(game, NULL, MAP_ERR);
		x++;
	}
}

static void	final_check(t_game **game, int size, int i, int j)
{
	if ((*game)->map[i][j] == DOOR)
	{
		if (((*game)->map[i - 1][j] != WALL || (*game)->map[i + 1][j]
		!= WALL) && ((*game)->map[i][j - 1] != WALL ||
		(*game)->map[i][j + 1] != WALL))
			exit_error(game, NULL, MAP_ERR);
	}
	if (i == size - 1)
	{
		if ((*game)->map[i - 1][j] != WALL &&
		(*game)->map[i - 1][j] != HOLE)
			exit_error(game, NULL, MAP_ERR);
	}
}

int			finish_parse_map(t_game **game)
{
	int i;
	int	j;
	int size[2];

	if ((*game)->player.start_pos != 1)
		exit_error(game, NULL, MAP_ERR);
	i = 0;
	while ((*game)->map[++i])
	{
		size[1] = ft_strlen((*game)->map[i]);
		size[0] = ft_strlen((*game)->map[i - 1]);
		check_border(game, size[0] - 1, i, size[1]);
		check_border(game, size[1] - 1, i - 1, size[0]);
		j = -1;
		while ((*game)->map[i][++j])
		{
			if ((*game)->map[i][j] == HOLE)
			{
				check_left(game, (*game)->map, i, j);
				check_right(game, (*game)->map, i, j);
			}
			final_check(game, size[1], i, j);
		}
	}
	return (NO_ERR);
}
