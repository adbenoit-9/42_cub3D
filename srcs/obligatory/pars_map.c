/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:42:10 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 22:59:31 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		bonus(char *line, t_all **all)
{
	exit_game(all, line, MAL_ERR);
	return (NO_ERR);
}

int	add_map(char *line, t_all **all)
{
	int i;

	i = 0;
	if (!((*all)->map[(*all)->i_map] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		exit_game(all, line, MAL_ERR);
	while (line[i])
	{
		if (line[i] == OBJ)
		{
			if (!((*all)->sp.coor = realloc_doub((*all)->sp.coor, (*all)->sp.count + 1)))
				exit_game(all, line, MAL_ERR);
			(*all)->sp.coor[(*all)->sp.count][X] = i + 0.5;
			(*all)->sp.coor[(*all)->sp.count][Y] = (*all)->i_map + 0.5;
			(*all)->sp.count++;
		}
		(*all)->map[(*all)->i_map][i] = line[i];
		i++;
	}
	(*all)->map[(*all)->i_map][i] = 0;
	((*all)->i_map)++;
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
		exit_game(all, line, PARS_ERR);
	while (line[++j])
	{
		if ((*all)->i_map == 0 && line[j] != WALL && line[j] != HOLE)
			exit_game(all, line, PARS_ERR);
		i = 0;
		while (i < NB_CHAR && line[j] != str_char[i])
			i++;
		if (i > 3 && i < NB_CHAR)
		{
			(*all)->player.map[X] = j + 0.5;
			(*all)->player.map[Y] = (*all)->i_map + 0.5;
			(*all)->player.o = line[j];
			(*all)->pos++;
		}
		if (i == NB_CHAR)
			exit_game(all, line, PARS_ERR);
	}
	map_error(all);
	(*all)->map[(*all)->i_map] = 0;
	return (add_map(line, all));
}
