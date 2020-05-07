/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:21:57 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/05 12:58:00 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	pars_r(char *line, char **param, int i)
{
	int k;
	int j;

	k = i;
	j = 0;
	while (line[k] && line[k] >= '0' && line[k] <= '9')
	{
		k++;
		j++;
	}
	if (!(*param = malloc(sizeof(char) * (j + 1))))
		return (-1);
	j = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
	{
		(*param)[j] = line[i];
		i++;
		j++;
	}
	(*param)[j] = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] < '0' && line[i] > '9')
		return (-1);
	return (i);
}

static void	err_r(t_all **all, char *line, char *x, char *y)
{
		free(y);
		free(x);
		ft_error(all, line, PARS_ERR);
}

int		add_r(t_all **all, char *line)
{
	char *x;
	char *y;
	int	i;

	x = NULL;
	y = NULL;
	i = 0;
	if ((i = pars_r(line, &x, i)) == -1)
		err_r(all, line, x, y);
	if ((i = pars_r(line, &y, i)) == -1)
		err_r(all, line, x, y);
	if (i != ft_strlen(line))
		err_r(all, line, x, y);
	if (((*all)->r[0] = ft_atoi(x)) > 2560)
		(*all)->r[0] = 2560;
	if (((*all)->r[1] = ft_atoi(y)) > 1440)
		(*all)->r[1] = 1440;
	if ((*all)->r[0] == -1 || (*all)->r[1] == -1)
		err_r(all, line, x, y);
	free(line);
	free(y);
	free(x);
	return (ft_parsing(all));	
}

int		check_col(char *line, char *col, int i)
{
	int j;

	j = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
	{
		if (j == 3)
			return (-1);
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

int		add_col(t_all **all, char *line, int ident)
{
	char	red[4];
	char	green[4];
	char	blue[4];
	int		col[3];
	int		i;

	i = 0;
	if ((i = check_col(line, red, i)) == -1)
		ft_error(all, line, PARS_ERR);
	if (line[i] != ',')
		return (-1);
	i++;
	if ((i = check_col(line, green, i)) == -1)
		ft_error(all, line, PARS_ERR);
	if (line[i] != ',')
		return (-1);
	i++;
	if ((i = check_col(line, blue, i)) == -1)
		ft_error(all, line, PARS_ERR);
	if (i != ft_strlen(line))
		ft_error(all, line, PARS_ERR);
	i = 0;
	col[0] = ft_atoi(red);
	col[1] = ft_atoi(green);
	col[2] = ft_atoi(blue);
	while (i < 3)
	{
		if (col[i] < 0 || col[i] > 255)
			ft_error(all, line, PARS_ERR);
		i++;
	}
	if (ident == F)
	{
		if ((*all)->f != -1)
			ft_error(all, line, PARS_ERR);
		(*all)->f = ft_rgb(col[0], col[1], col[2]);
	}
	if (ident == C)
	{
		if ((*all)->c != -1)
			ft_error(all, line, PARS_ERR);
		(*all)->c = ft_rgb(col[0], col[1], col[2]);
	}
	free(line);
	return (ft_parsing(all));	
}