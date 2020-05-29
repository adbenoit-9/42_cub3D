/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:42:10 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 15:32:45 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	parse_map(char *line, t_all **all)
{
	int i;

	i = 0;
	if (!((*all)->map[(*all)->map_index] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		exit_error(all, line, MAL_ERR);
	while (line[i])
	{
		if (line[i] == OBJ || line[i] == OBJ1)
		{
			(*all)->sp.count++;
			if (!((*all)->sp.coor = realloc_doub((*all)->sp.coor, (*all)->sp.count)))
				exit_error(all, line, MAL_ERR);
			if (!((*all)->sp.type = realloc((*all)->sp.type, (*all)->sp.count + 1)))
				exit_error(all, NULL, MAL_ERR);
			(*all)->sp.coor[(*all)->sp.count - 1][X] = i + 0.5;
			(*all)->sp.coor[(*all)->sp.count - 1][Y] = (*all)->map_index+ 0.5;
			if (line[i] == OBJ)
				(*all)->sp.type[(*all)->sp.count - 1] = OBJ;
			else
			{
				(*all)->sp.type[(*all)->sp.count - 1] = OBJ1;
				(*all)->bonus.foe++;
			}
			(*all)->sp.type[(*all)->sp.count] = 0;
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
	static char str_char[NB_CHAR_B] = {WALL, OBJ, EMPT, HOLE, OBJ1, DOOR, NORTH, SOUTH, EAST, WEST};
	int			i;
	int			j;
	int			size;

	j = 0;
	size = ft_strlen(line);
	if ((line[0] != WALL && line[0] != HOLE) || (size > 0 && line[size - 1] != WALL && line[size - 1] != HOLE))
		exit_error(all, line, MAP_ERR);
	while (line[j])
	{
		if ((*all)->map_index== 0 && line[j] != WALL && line[j] != HOLE)
			exit_error(all, line, MAP_ERR);
		i = 0;
		while (i < NB_CHAR_B && line[j] != str_char[i])
			i++;
		if (i > 5 && i < NB_CHAR_B)
		{
			(*all)->player.map[X] = j + 0.5;
			(*all)->player.map[Y] = (*all)->map_index+ 0.5;
			(*all)->player.start_o = line[j];
			(*all)->player.start_pos++;
		}
		if (i == NB_CHAR_B)
			exit_error(all, line, MAP_ERR);
		j++;
	}
	check_line_border(all, (*all)->map, (*all)->map_index);
	(*all)->map[(*all)->map_index] = 0;
	return (parse_map(line, all));
}
