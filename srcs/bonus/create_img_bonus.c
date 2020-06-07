/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:16:38 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/07 23:40:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ray_casting(t_all **all)
{
	(*all)->screen.x = 0;
	ft_move(all);
	draw_door(all);
	draw_all_sprites(all, &(*all)->sp);
	draw_weapon(all, &(*all)->bonus.weap.img);
	draw_mini_map(all);
	draw_hearts(all);
	if ((*all)->bonus.foe == 0)
		draw_replay(all, &(*all)->bonus.win_game, 1, 1);
}

int			create_image(t_all **all)
{
	int i;

	(*all)->bonus.loop[1]++;
	(*all)->bonus.loop[0]++;
	if ((*all)->img.ptr != NULL)
	{
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
		mlx_clear_window((*all)->mlx, (*all)->win);
		(*all)->img.ptr = NULL;
	}
	(*all)->img.ptr = mlx_new_image((*all)->mlx, (*all)->r[X], (*all)->r[Y]);
	(*all)->img.bpp = 32;
	(*all)->img.size_line = (*all)->r[X] * 4;
	(*all)->img.endian = 0;
	(*all)->img.data = (int *)mlx_get_data_addr((*all)->img.ptr,
		&(*all)->img.bpp, &(*all)->img.size_line, &(*all)->img.endian);
	ray_casting(all);
	mlx_put_image_to_window((*all)->mlx, (*all)->win, (*all)->img.ptr, 0, 0);
	i = -1;
	while (++i < (*all)->sp.count)
		(*all)->sp.see[i] = 0;
	return (NO_ERR);
}
