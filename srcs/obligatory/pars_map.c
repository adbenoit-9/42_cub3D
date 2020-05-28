/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:42:10 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 14:11:51 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		bonus(char *line, t_all **all)
{
	exit_error(all, line, MAL_ERR);
	return (NO_ERR);
}

int	parse_map(char *line, t_all **all)
{
	int i;

	i = 0;
	if (!((*all)->map[(*all)->map_index] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		exit_error(all, line, MAL_ERR);
	while (line[i])
	{
		if (line[i] == OBJ)
		{
			if (!((*all)->sp.coor = realloc_doub((*all)->sp.coor, (*all)->sp.count + 1)))
				exit_error(all, line, MAL_ERR);
			(*all)->sp.coor[(*all)->sp.count][X] = i + 0.5;
			(*all)->sp.coor[(*all)->sp.count][Y] = (*all)->map_index+ 0.5;
			(*all)->sp.count++;
		}
		(*all)->map[(*all)->map_index][i] = line[i];
		i++;
	}
	(*all)->map[(*all)->map_index][i] = 0;
	((*all)->map_index)++;
	free(line);
	return (ft_parsing(all));
}

int	map(char *line, t_all **all)
{
	static char str_char[NB_CHAR] = {WALL, OBJ, EMPT, HOLE, NORTH, SOUTH, EAST, WEST};
	int			i;
	int			j;
	int			size;

	j = -1;
	size = ft_strlen(line);
	if ((line[0] != WALL && line[0] != HOLE) || (size > 0 && line[size - 1] != WALL && line[size - 1] != HOLE))
		exit_error(all, line, IMG_ERR);
	while (line[++j])
	{
		if ((*all)->map_index== 0 && line[j] != WALL && line[j] != HOLE)
			exit_error(all, line, IMG_ERR);
		i = 0;
		while (i < NB_CHAR && line[j] != str_char[i])
			i++;
		if (i > 3 && i < NB_CHAR)
		{
			(*all)->player.map[X] = j + 0.5;
			(*all)->player.map[Y] = (*all)->map_index+ 0.5;
			(*all)->player.start_o = line[j];
			(*all)->player.start_pos++;
		}
		if (i == NB_CHAR)
			exit_error(all, line, IMG_ERR);
	}
	check_line_border(all);
	(*all)->map[(*all)->map_index] = 0;
	return (parse_map(line, all));
}
