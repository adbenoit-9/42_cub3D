/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:56:05 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 15:56:34 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_sprites(t_all **all)
{
	free_tab_nb((void **)(*all)->sp.coor, (*all)->sp.count, 1);
	free_tab_nb((void **)(*all)->sp.pos, (*all)->sp.count, 1);
	free((*all)->sp.dead);
	free((*all)->sp.see);
	free((*all)->sp.dist);
	free((*all)->sp.type);
	if ((*all)->sp.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->sp.img.ptr);
	if ((*all)->bonus.s1.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.s1.img.ptr);
	if ((*all)->bonus.sa.img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.sa.img.ptr);
}

void	clear_textures(t_all **all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((*all)->text.ptr[i])
			mlx_destroy_image((*all)->mlx_ptr, (*all)->text.ptr[i]);
		if ((*all)->bonus.door.ptr[i])
			mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.door.ptr[i]);
		if ((*all)->bonus.weap.ptr[i])
			mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.weap.ptr[i]);
		i++;
	}
}

void	clear_img(t_all **all)
{
	if ((*all)->bonus.heart.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.heart.ptr);
	if ((*all)->bonus.dead.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.dead.ptr);
	if ((*all)->bonus.win.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->bonus.win.ptr);
	if ((*all)->img.ptr)
		mlx_destroy_image((*all)->mlx_ptr, (*all)->img.ptr);
}

void	clear_utils(t_all **all)
{
	free_tab_char((*all)->map, 1);
	free_tab_nb((void **)(*all)->path, 6, 0);
	free_tab_nb((void **)(*all)->bonus.path, NB_BON, 0);
	free((*all)->wall.dist);
	if ((*all)->win_ptr)
	{
		mlx_clear_window((*all)->mlx_ptr, (*all)->win_ptr);
		mlx_destroy_window((*all)->mlx_ptr, (*all)->win_ptr);
	}
	// system("leaks Cub3D");
}
