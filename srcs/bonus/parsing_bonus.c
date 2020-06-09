/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:16:19 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 23:05:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
				return (fill_path(line, game, i));
			else if (i == 5)
				return (parse_res(game, line));
			else
				return (parse_color(game, line, i));
		}
	}
	(*game)->state = BONUS;
	return (parse_bonus(line, game));
}

int			parse_map(char *line, t_game **game)
{
	static char str_char[NB_CHAR_B] = {WALL, OBJ, EMPT, HOLE, NORTH,
									SOUTH, EAST, WEST, OBJ1, DOOR};
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
		while (i < NB_CHAR_B && line[j] != str_char[i])
			i++;
		init_player_pos(game, line, i, j);
		if (i == NB_CHAR_B)
			exit_error(game, line, MAP_ERR);
	}
	(*game)->map_size++;
	check_map_end(game, (*game)->map, (*game)->map_size);
	return (fill_map(line, game));
}

static int	fill_bonus(char *line, t_game **game, int i)
{
	int j;

	j = 0;
	if (!((*game)->path_bonus[i] = malloc(sizeof(char) *
	(ft_strlen(line) + 1))))
		exit_error(game, line, MAL_ERR);
	while (line[j])
	{
		(*game)->path_bonus[i][j] = line[j];
		j++;
	}
	(*game)->path_bonus[i][j] = 0;
	free(line);
	return (read_file(game));
}

int			parse_bonus(char *line, t_game **game)
{
	static char *str_info[NB_BON] = {BON_W0, BON_W1, BON_W2, BON_W3, BON_SF,
	BON_SD, BON_DN, BON_DS, BON_DE, BON_DW, BON_LIFE, BON_LOSE, BON_WIN};
	int			i;

	i = 0;
	while (i < NB_BON)
	{
		if (ft_strncmp(str_info[i], line, 3) == TRUE)
		{
			line = ft_strtrim(line, " ", 3);
			return (fill_bonus(line, game, i));
		}
		i++;
	}
	(*game)->state = MAP;
	return (parse_map(line, game));
}

void		check_door(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	while ((*game)->map[i])
	{
		j = 0;
		while ((*game)->map[i][j])
		{
			if ((*game)->map[i][j] == DOOR)
			{
				if (((*game)->map[i - 1][j] != WALL || (*game)->map[i + 1][j]
				!= WALL) && ((*game)->map[i][j - 1] != WALL ||
				(*game)->map[i][j + 1] != WALL))
					exit_error(game, NULL, MAP_ERR);
			}
			j++;
		}
		i++;
	}
}
