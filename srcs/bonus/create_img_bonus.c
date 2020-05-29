/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:16:38 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 21:16:39 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ray_casting(t_all **all)
{
	ft_move(all);
	draw_door(all);
	draw_all_sprites(all, &(*all)->sp);
	draw_weapon(all);
	draw_hearts(all);
	draw_mini_map(all);
}

int			create_image(t_all **all)
{
	int i;

	(*all)->bonus.loop2++;
	(*all)->bonus.loop++;
	if ((*all)->img.ptr != NULL)
	{
		mlx_destroy_image((*all)->mlx_ptr, (*all)->img.ptr);
		mlx_clear_window((*all)->mlx_ptr, (*all)->win_ptr);
		(*all)->img.ptr = NULL;
	}
	(*all)->img.ptr = mlx_new_image((*all)->mlx_ptr, (*all)->r[X], (*all)->r[Y]);
	(*all)->img.bpp = 32;
	(*all)->img.size_line = (*all)->r[X] * 4;
	(*all)->img.endian = 0;
	(*all)->img.data = (int *)mlx_get_data_addr((*all)->img.ptr, &(*all)->img.bpp, &(*all)->img.size_line, &(*all)->img.endian);
	(*all)->screen.column = 0;
	ray_casting(all);
	mlx_put_image_to_window((*all)->mlx_ptr, (*all)->win_ptr, (*all)->img.ptr, 0, 0);
	i = -1;
	while (++i < (*all)->sp.count)
		(*all)->sp.see[i] = 0;
	return (NO_ERR);
}
