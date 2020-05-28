/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:48:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 14:42:17 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		exit_error(t_all **all, char *line, int err)
{
	free(line);
	line = NULL;
	free_tab_char((*all)->map);
	free_tab_char((*all)->path);
	free_tab_nb((void **)(*all)->sp.coor, (*all)->sp.count);
	free_tab_nb((void **)(*all)->sp.pos, (*all)->sp.count);
	free((*all)->sp.dead);
	free((*all)->sp.see);
	free((*all)->sp.dist);
	free((*all)->wall.dist);
	free_tab_char((*all)->bonus.path);
	free((*all)->sp.type);
	if ((*all)->text.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->text.ptr);
	if ((*all)->sp.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->sp.img.ptr);
	if ((*all)->bonus.s1.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.s1.img.ptr);
	if ((*all)->bonus.sa.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.sa.img.ptr);
	if ((*all)->bonus.heart.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.heart.img.ptr);
	if ((*all)->bonus.dead.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.dead.img.ptr);
	if ((*all)->bonus.win.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.win.ptr);
	if ((*all)->bonus.door.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.door.ptr);
	if ((*all)->bonus.weap.ptr)
			mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.weap.ptr);
	if ((*all)->img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->img.ptr);
	if ((*all)->win_ptr)
	{
		mlx_clear_window((*all)->mlx_ptr, (*all)->win_ptr);
		mlx_destroy_window((*all)->mlx_ptr, (*all)->win_ptr);
	}
	free(*all);
	if (err != NO_ERR)
		print_error(err);
	exit(EXIT_SUCCESS);
}

void		print_error(int err)
{
	char *err_mess[NB_ERR] = {"Parsing problem.", "Please enter a correct file.", "Memory problem.", "Please enter corrects arguments.", "Please enter corrects paths.", "Error is here."};

	if (err >= 0)
	{
		write(1, "Error\n", 6);
		write(1, err_mess[err], ft_strlen(err_mess[err])); 
		write (1, "\n", 1);
	}
	exit(EXIT_SUCCESS);
}
