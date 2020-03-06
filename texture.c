/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:34:57 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/05 18:31:31 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	put_text(t_all **all)
{
	int i;

	i = 0;
	(*all)->text.dim[X] = 64;
	(*all)->text.dim[Y] = 64;
	(*all)->text.bpp = 32;
	(*all)->text.size_line = (*all)->text.dim[X] * 4;
	(*all)->text.endian = 0;
	while (i < 4)
	{
		(*all)->text.ptr = mlx_xpm_file_to_image((*all)->mlx, (*all)->info[i], &(*all)->text.dim[X], &(*all)->text.dim[Y]);
		(*all)->text.data[i] = (int *)mlx_get_data_addr((*all)->text.ptr, &(*all)->text.bpp, &(*all)->text.size_line, &(*all)->text.endian);
		i++;
	}
}

void	complete_text(t_all **all)
{
	(*all)->wall.dist[(*all)->grid.column] = wall_dist(all);
	if ((*all)->wall.side % 2 == 0)
		(*all)->wall.hit = (*all)->player.map[Y] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[Y];
	else
		(*all)->wall.hit = (*all)->player.map[X] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[X];
	(*all)->wall.hit -= (int)(*all)->wall.hit;
	(*all)->text.pos[X] = (int)((*all)->wall.hit * (double)(*all)->text.dim[X]);
	if((*all)->wall.side == 0 && (*all)->wall.raydir[X] > 0)
		(*all)->text.pos[X] = (*all)->text.dim[X] - (*all)->text.pos[X] - 1;
	if((*all)->wall.side == 1 && (*all)->wall.raydir[Y] < 0)
		(*all)->text.pos[X] = (*all)->text.dim[X] - (*all)->text.pos[X] - 1;
}