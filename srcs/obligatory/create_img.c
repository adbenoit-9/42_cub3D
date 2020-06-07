/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:42:13 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/07 17:52:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_image(t_all **all)
{
	(*all)->bonus.loop[0]++;
	if ((*all)->img.ptr != NULL)
	{
		mlx_destroy_image((*all)->mlx, (*all)->img.ptr);
		mlx_clear_window((*all)->mlx, (*all)->win);
		(*all)->img.ptr = NULL;
	}
	(*all)->img.ptr = mlx_new_image((*all)->mlx, (*all)->r[X],
					(*all)->r[Y]);
	(*all)->img.bpp = 32;
	(*all)->img.size_line = (*all)->r[X] * 4;
	(*all)->img.endian = 0;
	(*all)->img.data = (int *)mlx_get_data_addr((*all)->img.ptr,
		&(*all)->img.bpp, &(*all)->img.size_line, &(*all)->img.endian);
	ft_move(all);
	(*all)->screen.x = 0;
	draw_wall(all);
	draw_sprite(all, &(*all)->sp);
	mlx_put_image_to_window((*all)->mlx, (*all)->win,
		(*all)->img.ptr, 0, 0);
	return (NO_ERR);
}
