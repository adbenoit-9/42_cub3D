/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:16:19 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/05 16:18:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			parse_info(char *line, t_all **all)
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
				return (fill_path(line, all, i));
			else if (i == 5)
				return (parse_res(all, line));
			else
				return (parse_color(all, line, i));
		}
	}
	(*all)->state = BONUS;
	return (parse_bonus(line, all));
}

int			parse_map(char *line, t_all **all)
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
		exit_error(all, line, MAP_ERR);
	while (line[++j])
	{
		if ((*all)->map_size == 0 && line[j] != WALL && line[j] != HOLE)
			exit_error(all, line, MAP_ERR);
		i = 0;
		while (i < NB_CHAR_B && line[j] != str_char[i])
			i++;
		init_player_pos(all, line, i, j);
		if (i == NB_CHAR_B)
			exit_error(all, line, MAP_ERR);
	}
	(*all)->map_size++;
	check_map_end(all, (*all)->map, (*all)->map_size);
	return (fill_map(line, all));
}

static int	fill_bonus(char *line, t_all **all, int i)
{
	int j;

	j = 0;
	if (!((*all)->bonus.path[i] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		exit_error(all, line, MAL_ERR);
	while (line[j])
	{
		(*all)->bonus.path[i][j] = line[j];
		j++;
	}
	(*all)->bonus.path[i][j] = 0;
	free(line);
	return (read_file(all));
}

int			parse_bonus(char *line, t_all **all)
{
	static char *str_info[NB_BON] = {BON_W0, BON_W1, BON_W2, BON_W3, BON_S1,
	BON_SA, BON_DN, BON_DS, BON_DE, BON_DW, BON_LIFE, BON_LOSE, BON_WIN};
	int			i;

	i = 0;
	while (i < NB_BON)
	{
		if (ft_strncmp(str_info[i], line, 3) == TRUE)
		{
			line = ft_strtrim(line, " ", 3);
			return (fill_bonus(line, all, i));
		}
		i++;
	}
	(*all)->state = MAP;
	return (parse_map(line, all));
}

void		check_door(t_all **all)
{
	int	i;
	int	j;

	i = 0;
	while ((*all)->map[i])
	{
		j = 0;
		while ((*all)->map[i][j])
		{
			if ((*all)->map[i][j] == DOOR)
			{
				if (((*all)->map[i - 1][j] != WALL || (*all)->map[i + 1][j]
				!= WALL) && ((*all)->map[i][j - 1] != WALL ||
				(*all)->map[i][j + 1] != WALL))
					exit_error(all, NULL, MAP_ERR);
			}
			j++;
		}
		i++;
	}
}
