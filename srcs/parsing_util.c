/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:30:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 14:39:06 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	str_to_color(t_game **game, char *line, int *col)
{
	char	red[4];
	char	green[4];
	char	blue[4];
	int		i;

	i = 0;
	if ((i = fill_col(line, red, i)) == -1)
		exit_error(game, line, COL_ERR);
	if (line[i] != ',')
		exit_error(game, line, COL_ERR);
	i++;
	if ((i = fill_col(line, green, i)) == -1)
		exit_error(game, line, COL_ERR);
	if (line[i] != ',')
		exit_error(game, line, COL_ERR);
	i++;
	if ((i = fill_col(line, blue, i)) == -1 || i != ft_strlen(line))
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
	int		w_max;
	int		h_max;

	w_max = 0;
	h_max = 0;
	mlx_mscreen_resolution(&w_max, &h_max);
	if ((*game)->r[X] != -1 || (*game)->r[Y] != -1)
		exit_error(game, line, RES_ERR);
	i = 0;
	if (((*game)->r[X] = fill_res(line, &i, w_max)) == -1)
		exit_error(game, line, RES_ERR);
	if (((*game)->r[Y] = fill_res(line, &i, h_max)) == -1)
		exit_error(game, line, RES_ERR);
	if (i != ft_strlen(line))
		exit_error(game, line, RES_ERR);
	free(line);
	return (read_file(game));
}

void		init_player_pos(t_game **game, char *line, int i, int j)
{
	if (i > 3 && i < 8)
	{
		(*game)->player.pos[X] = j + 0.5;
		(*game)->player.pos[Y] = (*game)->map_size + 0.5;
		(*game)->player.start_o = line[j];
		(*game)->player.start_pos++;
	}
}
