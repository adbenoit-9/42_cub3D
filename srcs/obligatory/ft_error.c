/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:48:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/02 11:33:21 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_error(t_all **all, char *line, int err)
{
	free(line);
	line = NULL;
	free_tab((*all)->map);
	free_tab((*all)->info);
	free((*all)->bonus.path);
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