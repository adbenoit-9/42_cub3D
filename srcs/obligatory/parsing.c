/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 15:26:37 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/07 15:26:45 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_info(char *line, t_all **all)
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
				return (fill_path(line, all, i));
			else if (i == 5)
				return (parse_res(all, line));
			else
				return (parse_color(all, line, i));
		}
	}
	(*all)->state = MAP;
	return (parse_map(line, all));
}

int		parse_map(char *line, t_all **all)
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
		exit_error(all, line, MAP_ERR);
	while (line[++j])
	{
		if ((*all)->map_size == 0 && line[j] != WALL && line[j] != HOLE)
			exit_error(all, line, MAP_ERR);
		i = 0;
		while (i < NB_CHAR && line[j] != str_char[i])
			i++;
		init_player_pos(all, line, i, j);
		if (i == NB_CHAR)
			exit_error(all, line, MAP_ERR);
	}
	(*all)->map_size++;
	check_map_end(all, (*all)->map, (*all)->map_size);
	return (fill_map(line, all));
}

int		parse_bonus(char *line, t_all **all)
{
	exit_error(all, line, MAL_ERR);
	return (NO_ERR);
}

void	set_sprite_coor(t_all **all, char *line, int i)
{
	if (line[i] == OBJ)
	{
		if (!((*all)->sp.coor = realloc_doub((*all)->sp.coor,
										(*all)->sp.count + 1)))
			exit_error(all, line, MAL_ERR);
		(*all)->sp.coor[(*all)->sp.count][X] = i + 0.5;
		(*all)->sp.coor[(*all)->sp.count][Y] = (*all)->map_size + 0.5;
		(*all)->sp.count++;
	}
}
