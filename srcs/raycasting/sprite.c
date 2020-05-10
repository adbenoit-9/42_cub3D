/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:10:15 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/09 14:25:29 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sprite(t_all **all, t_sprite *sp, char *path)
{
	sp->dim[X] = 0;
	sp->dim[Y] = 0;
	add_dim_xpm(all, path, &sp->dim[X], &sp->dim[Y]);
	sp->bpp = 32;
	sp->size_line = sp->dim[X] * 4;
	sp->endian = 0;
	if ((sp->ptr = mlx_xpm_file_to_image((*all)->mlx, path, &sp->dim[X], &sp->dim[Y])) == NULL)
		ft_error(all, NULL, PARS_ERR);
	sp->data = (int *)mlx_get_data_addr(sp->ptr, &sp->bpp, &sp->size_line, &sp->endian);
}

static void	sort_sprite(t_sprite *sp)
{
	double tmp;
	int i;
	int j;

	j = 0;
	while (j < sp->count)
	{
		i = 0;
		while (i < sp->count - 1)
		{
			if (sp->dist[i] < sp->dist[i + 1])
			{
				tmp = sp->dist[i];
				sp->dist[i] = sp->dist[i + 1];
				sp->dist[i + 1] = tmp;
				tmp = sp->coor[i][X];
				sp->coor[i][X] = sp->coor[i + 1][X];
				sp->coor[i + 1][X] = tmp;
				tmp = sp->coor[i][Y];
				sp->coor[i][Y] = sp->coor[i + 1][Y];
				sp->coor[i + 1][Y] = tmp;
			}
			i++;
		}
		j++;
	}
}

void	add_dist(t_all **all, t_sprite *sp, void (*sort)(t_sprite *))
{
	int i;

	i = 0;
	while (i < sp->count)
	{
		sp->dist[i] = pow((*all)->player.map[X] - sp->coor[i][X], 2) +
					pow((*all)->player.map[Y] - sp->coor[i][Y], 2);
		i++;
	}
	sort(sp);
}

void	print_sprite(t_all **all, t_sprite *sp)
{
	double	invdet;
	int		i;

	i = 0;
	add_dist(all, sp, sort_sprite);
	invdet = 1.0 / ((*all)->grid.plane[X] * (*all)->player.dir[Y] - (*all)->player.dir[X] * (*all)->grid.plane[Y]);
	while (i < sp->count)
	{
		raycast_sprite(all, sp, sp, invdet, i);
		i++;
	}
}

void	raycast_sprite(t_all **all, t_sprite *sp, t_sprite *img, double invdet, int i)
{
	double	transf[2];
	int		start[2];
	int		end[2];
	int		tex[2];

	sp->pos[i][X] = sp->coor[i][X] - (*all)->player.map[X];
	sp->pos[i][Y] = sp->coor[i][Y] - (*all)->player.map[Y];
	transf[X] = invdet * ((*all)->player.dir[Y] * sp->pos[i][X] - (*all)->player.dir[X] * sp->pos[i][Y]);
	transf[Y] = invdet * ((*all)->grid.plane[X] * sp->pos[i][Y] - (*all)->grid.plane[Y] * sp->pos[i][X]);
	sp->h = abs((int)((*all)->r[Y] / transf[Y]));
	sp->w = abs((int)((*all)->r[Y] / transf[Y]));
	sp->screen = (int)(((*all)->r[X] / 2) * (1 + transf[X] / transf[Y]));
	end[Y] = sp->h / 2 + (*all)->r[Y] / 2;
	if (end[Y] >= (*all)->r[Y])
		end[Y] = (*all)->r[Y] - 1;
	start[X] = sp->screen - sp->w / 2;
	if (start[X] < 0)
		start[X] = 0;
	end[X] = sp->w / 2 + sp->screen;
	if (end[X] >= (*all)->r[X])
		end[X] = (*all)->r[X] - 1;
	while (start[X] < end[X])
	{
		tex[X] = (int)(256 * (start[X] - (sp->screen - sp->w / 2)) * img->dim[X] / sp->w) / 256;
		start[Y] = (*all)->r[Y] / 2 - sp->h / 2;
		if (start[Y] < 0)
			start[Y] = 0;
		while (start[Y] < end[Y] && transf[Y] > 0 && start[X] > 0 && start[X] < (*all)->r[X] && transf[Y] < (*all)->wall.dist[start[X]])
		{
			sp->see[i] = 1;
			tex[Y] = (((start[Y] * 256 - (*all)->r[Y] * 128 + sp->h * 128) * img->dim[Y]) / sp->h) / 256;
			if (img->data[(int)(img->dim[X] * tex[Y] + tex[X])] != -16777216)
				(*all)->img.data[start[X] + (*all)->r[X] * start[Y]] = img->data[(int)(img->dim[X] * tex[Y] + tex[X])] + (*all)->bonus.col;
			start[Y]++;
		}
		start[X]++;
	}
	i++;
}