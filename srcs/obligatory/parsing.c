/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:26:37 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/09 11:24:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_info(char *line, t_game **game)
{
	static char *str_info[NB_INFO] = {INF_WE, INF_NO, INF_EA,
						INF_SO, INF_S, INF_R, INF_F, INF_C};
	int			i;
	int			size;

	i = -1;
	while (++i < NB_INFO)
	{
		size = i < 4 ? 3 : 2;
		if (ft_strncmp(str_info[i], line, size) == TRUE)
		{
			line = ft_strtrim(line, " ", size);
			if (i < 5)
				return (fill_path(line, game, i));
			else if (i == 5)
				return (parse_res(game, line));
			else
				return (parse_color(game, line, i));
		}
	}
	(*game)->state = MAP;
	return (parse_map(line, game));
}

int		parse_map(char *line, t_game **game)
{
	static char str_char[NB_CHAR] = {WALL, OBJ, EMPT, HOLE, NORTH,
									SOUTH, EAST, WEST};
	int			i;
	int			j;
	int			size;

	j = -1;
	size = ft_strlen(line);
	if ((line[0] != WALL && line[0] != HOLE) ||
	(size > 0 && line[size - 1] != WALL && line[size - 1] != HOLE))
		exit_error(game, line, MAP_ERR);
	while (line[++j])
	{
		if ((*game)->map_size == 0 && line[j] != WALL && line[j] != HOLE)
			exit_error(game, line, MAP_ERR);
		i = 0;
		while (i < NB_CHAR && line[j] != str_char[i])
			i++;
		init_player_pos(game, line, i, j);
		if (i == NB_CHAR)
			exit_error(game, line, MAP_ERR);
	}
	(*game)->map_size++;
	check_map_end(game, (*game)->map, (*game)->map_size);
	return (fill_map(line, game));
}

int		parse_bonus(char *line, t_game **game)
{
	exit_error(game, line, MAL_ERR);
	return (NO_ERR);
}

void	set_sprite_coor(t_game **game, char *line, int i)
{
	if (line[i] == OBJ)
	{
		if (!((*game)->sp.coor = realloc_doub((*game)->sp.coor,
										(*game)->sp.count + 1)))
			exit_error(game, line, MAL_ERR);
		(*game)->sp.coor[(*game)->sp.count][X] = i + 0.5;
		(*game)->sp.coor[(*game)->sp.count][Y] = (*game)->map_size - 1 + 0.5;
		(*game)->sp.count++;
	}
}
