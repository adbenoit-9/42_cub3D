/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:48:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/03 17:52:53 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error(t_all **all, char *line, int err)
{
	(*all)->err = err;
	if ((*all)->ret == 0)
		return (1);
	free(line);
	line = NULL;
	free_tab((*all)->map);
	free_tab((*all)->info);
	return (0);
}

int	map_error(t_all **all, char *line)
{
	int j;

	j = 0;
	if ((*all)->state == END)
	{
		while ((*all)->map[(*all)->i_map - 1][j])
		{
			if ((*all)->map[(*all)->i_map - 1][j] != WALL && (*all)->map[(*all)->i_map - 1][j] != HOLE)
				return (ft_error(all, line, PARS_ERR));
			j++;
		}
		return (NO_ERR);
	}
	if (!((*all)->map = realloc_tab((*all)->map, (*all)->i_map + 2)))
		return (ft_error(all, line, PARS_ERR));
	return (NO_ERR);
}

int		print_err(int err)
{
	char *err_mess[NB_ERR] = {"Parsing problem.", "Please enter a correct file."};

	if (err >= 0)
	{
		write(1, "Error\n", 6);
		write(1, err_mess[err], ft_strlen(err_mess[err])); 
		write (1, "\n", 1);
	}
	return (0);
}

void	verif_hole(t_all **all, int i)
{
	int j;

	j = 0;
	while ((*all)->map[i][j])
	{
		if ((*all)->map[i][j] == HOLE)
		{
			if (j != 0 && (*all)->map[i][j - 1] != HOLE && (*all)->map[i][j - 1] != WALL)
				(*all)->err = PARS_ERR;
			if (j != ft_strlen((*all)->map[i]) - 1 && (*all)->map[i][j + 1] != HOLE && (*all)->map[i][j + 1] != WALL)
				(*all)->err = PARS_ERR;
			if (i != 0 && (*all)->map[i - 1][j] != HOLE && (*all)->map[i - 1][j] != WALL)
				(*all)->err = PARS_ERR;
			if (i != (*all)->i_map - 1 && (*all)->map[i + 1][j] != HOLE && (*all)->map[i + 1][j] != WALL)
				(*all)->err = PARS_ERR;
		}
		j++;
	}
}
int		map_end_error(t_all **all)
{
	int i;
	int	j;
	int size1;
	int	size2;

	if ((*all)->pos != 1)
		return (PARS_ERR);
	i = 0;
	size1 = 0;
	size2 = 0;
	while ((*all)->map[i])
	{
		j = -1;
		size2 = ft_strlen((*all)->map[i]);
		if (i != 0)
			size1 = ft_strlen((*all)->map[i - 1]);
		if (i == 0)
			size1 = ft_strlen((*all)->map[i + 1]);
		if (size1 > size2 && i != 0)
			j = size2;
		while (j != -1 && (*all)->map[i - 1][j])
		{
			if ((*all)->map[i - 1][j] != WALL)
				return (PARS_ERR);
			j++;
		}
		j = -1;
		if (size2 > size1 && i != (*all)->i_map - 1)
			j = size1;
		while (j != -1 && (*all)->map[i][j])
		{
			if ((*all)->map[i][j] != WALL)
				return (PARS_ERR);
			j++;
		}
		verif_hole(all, i);
		i++;
	}
	return ((*all)->err);
}