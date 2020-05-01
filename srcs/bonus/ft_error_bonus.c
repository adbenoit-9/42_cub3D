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

void		ft_error(t_all **all, char *line, int err)
{
	free(line);
	line = NULL;
	free_tab((*all)->map);
	free_tab((*all)->info);
	free((*all)->wall.dist);
	//free((*all)->img.data);
	free((*all)->text.ptr);
	//free((*all)->text.data);
	//free_tab((char **)(*all)->sp.pos);
	//free_tab((char **)(*all)->sp.coor);
	free((*all)->sp.ptr);
	//free((*all)->sp.data);
	//free((*all)->sp.dist);
	free(*all);
	if (err != NO_ERR)
		print_err(err);
	if ((*all)->img.ptr)
	{
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
		mlx_clear_window((*all)->mlx, (*all)->win);
	}
	if ((*all)->win)
		mlx_destroy_window((*all)->mlx, (*all)->win);
	//system("leaks cub3d");
	exit(EXIT_SUCCESS);
}

int			map_error(t_all **all, char *line)
{
	int j;

	j = 0;
	if ((*all)->state == END)
	{
		while ((*all)->map[(*all)->i_map - 1][j])
		{
			if ((*all)->map[(*all)->i_map - 1][j] != WALL && (*all)->map[(*all)->i_map - 1][j] != HOLE)
				ft_error(all, line, PARS_ERR);
			j++;
		}
		return (NO_ERR);
	}
	if (!((*all)->map = realloc_tab((*all)->map, (*all)->i_map + 2)))
		ft_error(all, line, MAL_ERR);
	return (NO_ERR);
}

void		print_err(int err)
{
	char *err_mess[NB_ERR] = {"Parsing problem.", "Please enter a correct file.", "Memory problem.", "Please enter corrects arguments.", "Please enter corrects paths."};

	if (err >= 0)
	{
		write(1, "Error\n", 6);
		write(1, err_mess[err], ft_strlen(err_mess[err])); 
		write (1, "\n", 1);
	}
	exit(EXIT_SUCCESS);
}
