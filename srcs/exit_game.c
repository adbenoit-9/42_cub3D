/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:48:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 22:59:07 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void static	destroy_tab_img(t_all **all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((*all)->text.ptr[i])
			mlx_destroy_image((*all)->mlx, (*all)->text.ptr[i]);
		if ((*all)->bonus.door.ptr[i])
			mlx_destroy_image((*all)->mlx, (*all)->bonus.door.ptr[i]);
		if ((*all)->bonus.weap.ptr[i])
			mlx_destroy_image((*all)->mlx, (*all)->bonus.weap.ptr[i]);
		i++;
	}
		if ((*all)->win)
	{
		mlx_clear_window((*all)->mlx, (*all)->win);
		mlx_destroy_window((*all)->mlx, (*all)->win);
	}
}

void static	destroy_img(t_all **all)
{
	if ((*all)->sp.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->sp.img.ptr);
	if ((*all)->bonus.s1.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.s1.img.ptr);
	if ((*all)->bonus.sa.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.sa.img.ptr);
	if ((*all)->bonus.heart.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.heart.ptr);
	if ((*all)->bonus.dead.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.dead.ptr);
	if ((*all)->bonus.win.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.win.ptr);
	if ((*all)->img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
}

void		exit_game(t_all **all, char *line, int code)
{
	free(line);
	line = NULL;
	free_tab_char((*all)->map, 1);
	free_tab_nb((void **)(*all)->info, 6, 0);
	free_tab_nb((void **)(*all)->bonus.path, NB_BON, 0);
	free_tab_nb((void **)(*all)->sp.coor, (*all)->sp.count, 1);
	free_tab_nb((void **)(*all)->sp.pos, (*all)->sp.count, 1);
	free((*all)->sp.dead);
	free((*all)->sp.see);
	free((*all)->sp.dist);
	free((*all)->wall.dist);
	free((*all)->sp.type);
	destroy_img(all);
	destroy_tab_img(all);
	free(*all);
	system("leaks Cub3D");
	if (code != NO_ERR)
		print_err(code);
	else
		write(1, "destroy window done.\n", 21);
	exit(EXIT_SUCCESS);
}

void		print_err(int err)
{
	char *err_mess[NB_ERR] = {"Parsing problem.", "Failed to open file", "failed to malloc.",
							"Please enter corrects arguments.", "failed to load image.", "mlx failed to create window or image."};

	if (err >= 0)
	{
		write(1, "Error\n", 6);
		write(1, err_mess[err], ft_strlen(err_mess[err])); 
		write (1, "\n", 1);
	}
	exit(EXIT_FAILURE);
}