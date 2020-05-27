/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:48:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 14:42:17 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		exit_game(t_all **all, char *line, int err)
{
	free(line);
	line = NULL;
	free_tab_char((*all)->map);
	free_tab_char((*all)->info);
	free_tab_nb((void **)(*all)->sp.coor, (*all)->sp.count);
	free_tab_nb((void **)(*all)->sp.pos, (*all)->sp.count);
	free((*all)->sp.dead);
	free((*all)->sp.see);
	free((*all)->sp.dist);
	free((*all)->wall.dist);
	free_tab_char((*all)->bonus.path);
	free((*all)->sp.type);
	if ((*all)->text.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->text.ptr);
	if ((*all)->sp.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->sp.img.ptr);
	if ((*all)->bonus.s1.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.s1.img.ptr);
	if ((*all)->bonus.sa.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.sa.img.ptr);
	if ((*all)->bonus.heart.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.heart.img.ptr);
	if ((*all)->bonus.dead.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.dead.img.ptr);
	if ((*all)->bonus.win.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.win.ptr);
	if ((*all)->bonus.door.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.door.ptr);
	if ((*all)->bonus.weap.ptr)
			mlx_destroy_image((*all)->mlx, (*all)->bonus.weap.ptr);
	if ((*all)->img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
	if ((*all)->win)
	{
		mlx_clear_window((*all)->mlx, (*all)->win);
		mlx_destroy_window((*all)->mlx, (*all)->win);
	}
	free(*all);
	if (err != NO_ERR)
		print_err(err);
	exit(EXIT_SUCCESS);
}

void		print_err(int err)
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
