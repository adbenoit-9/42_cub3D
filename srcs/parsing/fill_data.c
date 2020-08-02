/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:10:10 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:25:01 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			fill_path(char *line, t_game **game, char **path)
{
	int j;

	j = 0;
	if (*path)
		exit_error(game, line, IMG_ERR);
	if (!((*path) = ft_realloc((*path), ft_strlen(line) + 1)))
		exit_error(game, line, MAL_ERR);
	while (line[j])
	{
		(*path)[j] = line[j];
		j++;
	}
	(*path)[j] = 0;
	free(line);
	return (read_file(game));
}

static void	set_sprite_coor(t_game **game, char *line, int i)
{
	int	size;

	if (line[i] == OBJ)
	{
		(*game)->sp.count++;
		size = (*game)->sp.count;
		if (!((*game)->sp.coor = realloc_doub((*game)->sp.coor, size)))
			exit_error(game, line, MAL_ERR);
		(*game)->sp.coor[size - 1][X] = i + 0.5;
		(*game)->sp.coor[size - 1][Y] = (*game)->map_size - 1 + 0.5;
	}
}

int			fill_map(char *line, t_game **game)
{
	int i;
	int	size;

	size = (*game)->map_size;
	if (!((*game)->map = realloc_tab((*game)->map, size + 1)))
		exit_error(game, NULL, MAL_ERR);
	if (!((*game)->map[size - 1] = malloc(sizeof(char)
									* (ft_strlen(line) + 1))))
		exit_error(game, line, MAL_ERR);
	i = 0;
	while (line[i])
	{
		set_sprite_coor(game, line, i);
		(*game)->map[size - 1][i] = line[i];
		i++;
	}
	(*game)->map[size - 1][i] = 0;
	free(line);
	return (read_file(game));
}

int			fill_res(char *line, int *i, int max)
{
	int		nb;

	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] >= '0' && line[*i] <= '9')
		nb = ft_atoi(line + *i);
	else
		nb = -1;
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	nb = nb > max ? max : nb;
	return (nb);
}
