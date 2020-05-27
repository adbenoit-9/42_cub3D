/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:10:15 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 14:47:45 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_sprite_pixel(t_all **all, t_sprite *sp, t_img *sp_img, int *end)
{
	int	pix[2];
	int	start[2];

	start[X] = sp->screen - sp->w / 2;
	if (start[X] < 0)
		start[X] = 0;
	while (start[X] < end[X])
	{
		pix[X] = (int)(256 * (start[X] - (sp->screen - sp->w / 2)) * sp_img->dim[X] / sp->w) / 256;
		start[Y] = (*all)->r[Y] / 2 - sp->h / 2;
		if (start[Y] < 0)
			start[Y] = 0;
		while (start[Y] < end[Y] && sp->transf[Y] > 0 && start[X] > 0 &&
					start[X] < (*all)->r[X] && sp->transf[Y] < (*all)->wall.dist[start[X]])
		{
			sp->see[sp->index] = 1;
			pix[Y] = (((start[Y] * 256 - (*all)->r[Y] * 128 + sp->h * 128) * sp_img->dim[Y]) / sp->h) / 256;
			if (sp_img->data[(int)(sp_img->dim[X] * pix[Y] + pix[X])] != -16777216)
				(*all)->img.data[start[X] + (*all)->r[X] * start[Y]] =
									sp_img->data[(int)(sp_img->dim[X] * pix[Y] + pix[X])] + (*all)->bonus.col;
			start[Y]++;
		}
		start[X]++;
	}
}

void		raycast_sprite(t_all **all, t_sprite *sp, t_img *sp_img)
{
	int		end[2];
	int		i;

	i = sp->index;
	sp->pos[i][X] = sp->coor[i][X] - (*all)->player.map[X];
	sp->pos[i][Y] = sp->coor[i][Y] - (*all)->player.map[Y];
	sp->transf[X] = (*all)->invdet * ((*all)->player.dir[Y] * sp->pos[i][X] - (*all)->player.dir[X] * sp->pos[i][Y]);
	sp->transf[Y] = (*all)->invdet * ((*all)->grid.plane[X] * sp->pos[i][Y] - (*all)->grid.plane[Y] * sp->pos[i][X]);
	sp->h = abs((int)((*all)->r[Y] / sp->transf[Y]));
	sp->w = abs((int)((*all)->r[Y] / sp->transf[Y]));
	sp->screen = (int)(((*all)->r[X] / 2) * (1 + sp->transf[X] / sp->transf[Y]));
	end[Y] = sp->h / 2 + (*all)->r[Y] / 2;
	if (end[Y] >= (*all)->r[Y])
		end[Y] = (*all)->r[Y] - 1;
	end[X] = sp->w / 2 + sp->screen;
	if (end[X] >= (*all)->r[X])
		end[X] = (*all)->r[X] - 1;
	add_sprite_pixel(all, sp, sp_img, end);
}

void		print_sprite(t_all **all, t_sprite *sp)
{
	int		i;

	i = 0;
	add_dist(all, sp, sort_sprite);
	(*all)->invdet = 1.0 / ((*all)->grid.plane[X] * (*all)->player.dir[Y] - (*all)->player.dir[X] * (*all)->grid.plane[Y]);
	while (i < sp->count)
	{
		sp->index = i;
		raycast_sprite(all, sp, &sp->img);
		i++;
	}
}