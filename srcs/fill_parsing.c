/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:10:10 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/05 16:11:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_path(char *line, t_all **all, int i)
{
	int j;

	j = 0;
	if ((*all)->path[i])
		exit_error(all, line, IMG_ERR);
	if (!((*all)->path[i] = ft_realloc((*all)->path[i], ft_strlen(line) + 1)))
		exit_error(all, line, "MAL_ERR");
	while (line[j])
	{
		(*all)->path[i][j] = line[j];
		j++;
	}
	(*all)->path[i][j] = 0;
	free(line);
	return (read_file(all));
}

int	fill_map(char *line, t_all **all)
{
	int i;

	i = 0;
	if (!((*all)->map[(*all)->map_size - 1] = malloc(sizeof(char)
									* (ft_strlen(line) + 1))))
		exit_error(all, line, MAL_ERR);
	while (line[i])
	{
		set_sprite_coor(all, line, i);
		(*all)->map[(*all)->map_size - 1][i] = line[i];
		i++;
	}
	(*all)->map[(*all)->map_size - 1][i] = 0;
	free(line);
	return (read_file(all));
}

int	fill_res(char *line, int *i, int max)
{
	int		j;
	int		nb;
	char	*x;

	j = *i;
	while (line[j] >= '0' && line[j] <= '9')
		j++;
	j -= *i;
	if (!(x = malloc(sizeof(char) * (j + 1))))
		return (-1);
	j = -1;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		x[++j] = line[*i];
		(*i)++;
	}
	x[j] = 0;
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] < '0' && line[*i] > '9')
		return (-1);
	nb = ft_atoi(x);
	free(x);
	nb = nb > max ? max : nb;
	return (nb);
}

int	fill_col(char *line, char *col, int i)
{
	int j;

	j = 0;
	while (j < 3 && line[i] >= '0' && line[i] <= '9')
	{
		col[j] = line[i];
		i++;
		j++;
	}
	while (j < 4)
	{
		col[j] = 0;
		j++;
	}
	return (i);
}
