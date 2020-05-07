/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:34:57 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/06 18:35:23 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_text(t_all **all)
{
	int i;

	i = 0;
	(*all)->text.bpp = 32;
	(*all)->text.endian = 0;
	while (i < 4)
	{
		(*all)->text.dim[i][X] = 0;
		(*all)->text.dim[i][Y] = 0;
		add_dim_xpm(all, (*all)->info[i], &(*all)->text.dim[i][X], &(*all)->text.dim[i][Y]);
		(*all)->text.size_line = (*all)->text.dim[i][X] * 4;
		if (((*all)->text.ptr = mlx_xpm_file_to_image((*all)->mlx, (*all)->info[i], &(*all)->text.dim[i][X], &(*all)->text.dim[i][Y])) == NULL)
			ft_error(all, NULL, PARS_ERR);
		(*all)->text.data[i] = (int *)mlx_get_data_addr((*all)->text.ptr, &(*all)->text.bpp, &(*all)->text.size_line, &(*all)->text.endian);
		i++;
	}
}

void	complete_text(t_all **all)
{
	(*all)->wall.dist[(*all)->grid.column] = wall_dist(all, &(*all)->wall);
	if ((*all)->wall.side % 2 == 0)
		(*all)->wall.hit = (*all)->player.map[Y] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[Y];
	else
		(*all)->wall.hit = (*all)->player.map[X] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[X];
	(*all)->wall.hit -= (int)(*all)->wall.hit;
	(*all)->text.pos[X] = (int)((*all)->wall.hit * (double)(*all)->text.dim[(*all)->wall.side][X]);
	if((*all)->wall.side == 0 && (*all)->wall.raydir[X] > 0)
		(*all)->text.pos[X] = (*all)->text.dim[(*all)->wall.side][X] - (*all)->text.pos[X] - 1;
	if((*all)->wall.side == 1 && (*all)->wall.raydir[Y] < 0)
		(*all)->text.pos[X] = (*all)->text.dim[(*all)->wall.side][X] - (*all)->text.pos[X] - 1;
}