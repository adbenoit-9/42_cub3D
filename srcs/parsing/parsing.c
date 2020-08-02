/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:26:37 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:25:57 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_info(char *line, t_game **game)
{
	static char *str_info[NB_INFO] = {INF_EA, INF_SO, INF_WE, INF_NO,
									INF_S, INF_R, INF_F, INF_C};
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
				return (fill_path(line, game, &(*game)->path[i]));
			else if (i == 5)
				return (parse_res(game, line));
			else
				return (parse_color(game, line, i));
		}
	}
	(*game)->state = MAP;
	return (parse_map(line, game));
}

static void	init_player_pos(t_game **game, char *line, int i, int j)
{
	if (i > 3 && i < 8)
	{
		(*game)->player.pos[X] = j + 0.5;
		(*game)->player.pos[Y] = (*game)->map_size + 0.5;
		(*game)->player.start_o = line[j];
		(*game)->player.start_pos++;
	}
}

int			parse_map(char *line, t_game **game)
{
	static char str_char[NB_CHAR] = {WALL, OBJ, EMPT, HOLE, NORTH,
									SOUTH, EAST, WEST};
	int			i;
	int			j;
	int			size;

	j = -1;
	size = ft_strlen(line);
	if ((line[0] != WALL && line[0] != HOLE) || (size > 0 &&
	line[size - 1] != WALL && line[size - 1] != HOLE))
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
	return (fill_map(line, game));
}
