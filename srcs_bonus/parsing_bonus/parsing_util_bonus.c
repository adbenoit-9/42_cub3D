/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:30:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/07 16:47:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_color(char *line, char *col, int i)
{
	int j;

	j = 0;
	while (j < 3 && line[i] >= '0' && line[i] <= '9')
	{
		col[j] = line[i];
		i++;
		j++;
	}
	col[j] = 0;
	return (i);
}

static void	str_to_color(t_game **game, char *line, int *col)
{
	char	red[4];
	char	green[4];
	char	blue[4];
	int		i;

	i = 0;
	i = get_color(line, red, i);
	if (line[i] != ',')
		exit_error(game, line, COL_ERR);
	i++;
	i = get_color(line, green, i);
	if (line[i] != ',')
		exit_error(game, line, COL_ERR);
	i++;
	i = get_color(line, blue, i);
	if (i != ft_strlen(line))
		exit_error(game, line, COL_ERR);
	col[0] = ft_atoi(red);
	col[1] = ft_atoi(green);
	col[2] = ft_atoi(blue);
}

int			parse_color(t_game **game, char *line, int ident)
{
	int		col[3];
	int		i;

	str_to_color(game, line, col);
	i = 0;
	while (i < 3)
	{
		if (col[i] < 0 || col[i] > 255)
			exit_error(game, line, COL_ERR);
		i++;
	}
	if (ident == F)
	{
		if ((*game)->f != -1)
			exit_error(game, line, COL_ERR);
		(*game)->f = ft_rgb(col[0], col[1], col[2]);
	}
	if (ident == C)
	{
		if ((*game)->c != -1)
			exit_error(game, line, COL_ERR);
		(*game)->c = ft_rgb(col[0], col[1], col[2]);
	}
	free(line);
	return (read_file(game));
}

int			parse_res(t_game **game, char *line)
{
	int		i;

	if ((*game)->r[X] != -1 || (*game)->r[Y] != -1)
		exit_error(game, line, RES_ERR);
	i = 0;
	if (((*game)->r[X] = fill_res(line, &i)) == -1)
		exit_error(game, line, RES_ERR);
	if (((*game)->r[Y] = fill_res(line, &i)) == -1)
		exit_error(game, line, RES_ERR);
	if (i != ft_strlen(line))
		exit_error(game, line, RES_ERR);
	free(line);
	if ((*game)->r[X] == 0 || (*game)->r[Y] == 0)
		exit_game(game);
	return (read_file(game));
}
