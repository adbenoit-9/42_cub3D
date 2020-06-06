/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:56:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:48:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_sprites(t_all **all)
{
	free_tab_nb((void **)(*all)->sp.coor, (*all)->sp.count);
	free_tab_nb((void **)(*all)->sp.pos, (*all)->sp.count);
	free((*all)->sp.dead);
	free((*all)->sp.see);
	free((*all)->sp.dist);
	free((*all)->sp.type);
	if ((*all)->sp.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->sp.img.ptr);
	if ((*all)->bonus.s1.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.s1.img.ptr);
	if ((*all)->bonus.sa.img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.sa.img.ptr);
}

void	clear_textures(t_all **all)
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
}

void	clear_bonus(t_all **all)
{
	if ((*all)->bonus.heart.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.heart.ptr);
	if ((*all)->bonus.dead.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.dead.ptr);
	if ((*all)->bonus.win.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->bonus.win.ptr);
	free_tab_nb((void **)(*all)->bonus.path, NB_BON);
}

void	clear_utils(t_all **all)
{
	free_tab_char((*all)->map);
	free_tab_nb((void **)(*all)->path, 4);
	free((*all)->wall.dist);
	if ((*all)->img.ptr)
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
	if ((*all)->win)
	{
		mlx_clear_window((*all)->mlx, (*all)->win);
		mlx_destroy_window((*all)->mlx, (*all)->win);
	}
	// system("leaks Cub3D");
}
