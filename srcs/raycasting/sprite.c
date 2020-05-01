/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:10:15 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/06 15:31:22 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sprite(t_all **all)
{
	(*all)->sp.dim[X] = 0;
	(*all)->sp.dim[Y] = 0;
	add_dim_xpm(all, (*all)->info[S], &(*all)->sp.dim[X], &(*all)->sp.dim[Y]);
	(*all)->sp.bpp = 32;
	(*all)->sp.size_line = (*all)->sp.dim[X] * 4;
	(*all)->sp.endian = 0;
	if (((*all)->sp.ptr = mlx_xpm_file_to_image((*all)->mlx, (*all)->info[S], &(*all)->sp.dim[X], &(*all)->sp.dim[Y])) == NULL)
		ft_error(all, NULL, PARS_ERR);
	(*all)->sp.data = (int *)mlx_get_data_addr((*all)->sp.ptr, &(*all)->sp.bpp, &(*all)->sp.size_line, &(*all)->sp.endian);
}

void	sort_sprite(t_all **all)
{
	double tmp;
	int i;
	int j;

	j = 0;
	while (j < (*all)->sp.count)
	{
		i = 0;
		while (i < (*all)->sp.count - 1)
		{
			if ((*all)->sp.dist[i] < (*all)->sp.dist[i + 1])
			{
				tmp = (*all)->sp.dist[i];
				(*all)->sp.dist[i] = (*all)->sp.dist[i + 1];
				(*all)->sp.dist[i + 1] = tmp;
				tmp = (*all)->sp.pos[i][X];
				(*all)->sp.pos[i][X] = (*all)->sp.pos[i + 1][X];
				(*all)->sp.pos[i + 1][X] = tmp;
				tmp = (*all)->sp.pos[i][Y];
				(*all)->sp.pos[i][Y] = (*all)->sp.pos[i + 1][Y];
				(*all)->sp.pos[i + 1][Y] = tmp;
			}
			i++;
		}
		j++;
	}
}

void	add_dist(t_all **all)
{
	int i;

	i = 0;
	if (!(((*all))->sp.dist = malloc(sizeof(double) * (*all)->sp.count)))
		ft_error(all, NULL, MAL_ERR);
	if (!(((*all))->sp.pos = malloc(sizeof(double *) * (*all)->sp.count)))
		ft_error(all, NULL, MAL_ERR);
	while (i < (*all)->sp.count)
	{
		if (!(((*all))->sp.pos[i] = malloc(sizeof(double) * 2)))
			ft_error(all, NULL, MAL_ERR);
		i++;
	}
	i = 0;
	while (i < (*all)->sp.count)
	{
		(*all)->sp.dist[i] = pow((*all)->player.map[X] - (*all)->sp.coor[i][X], 2) + pow((*all)->player.map[Y] - (*all)->sp.coor[i][Y], 2);
		i++;
	}
	sort_sprite(all);
}

void	raycast_sprite(t_all **all)
{
	int		i;
	double	invdet;
	double	transf[2];
	int		start[2];
	int		end[2];
	int		tex[2];

	i = 0;
	add_dist(all);
	invdet = 1.0 / ((*all)->grid.plane[X] * (*all)->player.dir[Y] - (*all)->player.dir[X] * (*all)->grid.plane[Y]);
	while (i < (*all)->sp.count)
	{
		(*all)->sp.pos[i][X] = (*all)->sp.coor[i][X] - (*all)->player.map[X];
		(*all)->sp.pos[i][Y] = (*all)->sp.coor[i][Y] - (*all)->player.map[Y];
		transf[X] = invdet * ((*all)->player.dir[Y] * (*all)->sp.pos[i][X] - (*all)->player.dir[X] * (*all)->sp.pos[i][Y]);
		transf[Y] = invdet * ((*all)->grid.plane[X] * (*all)->sp.pos[i][Y] - (*all)->grid.plane[Y] * (*all)->sp.pos[i][X]);
		(*all)->sp.h = abs((int)((*all)->r[Y] / transf[Y]));
		(*all)->sp.w = abs((int)((*all)->r[Y] / transf[Y]));
		(*all)->sp.screen = (int)(((*all)->r[X] / 2) * (1 + transf[X] / transf[Y]));
		end[Y] = (*all)->sp.h / 2 + (*all)->r[Y] / 2;
		if (end[Y] >= (*all)->r[Y])
			end[Y] = (*all)->r[Y] - 1;
		start[X] = (*all)->sp.screen - (*all)->sp.w / 2;
		if (start[X] < 0)
			start[X] = 0;
		end[X] = (*all)->sp.w / 2 + (*all)->sp.screen;
		if (end[X] >= (*all)->r[X])
			end[X] = (*all)->r[X] - 1;
		while (start[X] < end[X])
		{
			tex[X] = (int)(256 * (start[X] - ((*all)->sp.screen - (*all)->sp.w / 2)) * (*all)->sp.dim[X] / (*all)->sp.w) / 256;
			start[Y] = (*all)->r[Y] / 2 - (*all)->sp.h / 2;
			if (start[Y] < 0)
				start[Y] = 0;
			while (start[Y] < end[Y] && transf[Y] > 0 && start[X] > 0 && start[X] < (*all)->r[X] && transf[Y] < (*all)->wall.dist[start[X]])
			{
				tex[Y] = (((start[Y] * 256 - (*all)->r[Y] * 128 + (*all)->sp.h * 128) * (*all)->sp.dim[Y]) / (*all)->sp.h) / 256;
				if ((*all)->sp.data[(int)((*all)->sp.dim[X] * tex[Y] + tex[X])] != -16777216)
					(*all)->img.data[start[X] + (*all)->r[X] * start[Y]] = (*all)->sp.data[(int)((*all)->sp.dim[X] * tex[Y] + tex[X])];
				start[Y]++;
			}
			start[X]++;
		}
		i++;
	}
}