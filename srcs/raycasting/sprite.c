/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:46:47 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:07:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sprite_pixel(t_all **all, t_sprite *sp, t_img *s_im, int *end)
{
	int	px[2];
	int	s[2];

	s[X] = sp->screen - sp->w / 2 - 1;
	if (s[X] < 0)
		s[X] = -1;
	while (++s[X] < end[X])
	{
		px[X] = (int)(256 * (s[X] - (sp->screen - sp->w / 2)) *
					s_im->dim[X] / sp->w) / 256;
		s[Y] = (*all)->r[Y] / 2 - sp->h / 2;
		if (s[Y] < 0)
			s[Y] = 0;
		while (s[Y] < end[Y] && sp->transf[Y] > 0 && s[X] > 0 && s[X]
				< (*all)->r[X] && sp->transf[Y] < (*all)->wall.dist[s[X]])
		{
			sp->see[sp->index] = TRUE;
			px[Y] = (((s[Y] * 256 - (*all)->r[Y] * 128 + sp->h * 128) *
						s_im->dim[Y]) / sp->h) / 256;
			if (s_im->data[(int)(s_im->dim[X] * px[Y] + px[X])] != -16777216)
				(*all)->img.data[s[X] + (*all)->r[X] * s[Y]] = s_im->data[(int)
							(s_im->dim[X] * px[Y] + px[X])] + (*all)->bonus.col;
			s[Y]++;
		}
	}
}

void		raycast_sprite(t_all **all, t_sprite *sp, t_img *sp_img)
{
	int		end[2];
	int		i;

	i = sp->index;
	sp->pos[i][X] = sp->coor[i][X] - (*all)->player.pos[X];
	sp->pos[i][Y] = sp->coor[i][Y] - (*all)->player.pos[Y];
	sp->transf[X] = (*all)->invdet * ((*all)->player.dir[Y] * sp->pos[i][X] -
					(*all)->player.dir[X] * sp->pos[i][Y]);
	sp->transf[Y] = (*all)->invdet * ((*all)->screen.plane[X] * sp->pos[i][Y] -
					(*all)->screen.plane[Y] * sp->pos[i][X]);
	sp->h = abs((int)((*all)->r[Y] / sp->transf[Y]));
	sp->w = abs((int)((*all)->r[Y] / sp->transf[Y]));
	sp->screen = (int)(((*all)->r[X] / 2) *
				(1 + sp->transf[X] / sp->transf[Y]));
	end[Y] = sp->h / 2 + (*all)->r[Y] / 2;
	if (end[Y] >= (*all)->r[Y])
		end[Y] = (*all)->r[Y] - 1;
	end[X] = sp->w / 2 + sp->screen;
	if (end[X] >= (*all)->r[X])
		end[X] = (*all)->r[X] - 1;
	draw_sprite_pixel(all, sp, sp_img, end);
}

void		draw_sprite(t_all **all, t_sprite *sp)
{
	int		i;

	i = 0;
	add_dist(all, sp, sort_sprite);
	(*all)->invdet = 1.0 / ((*all)->screen.plane[X] * (*all)->player.dir[Y] -
					(*all)->player.dir[X] * (*all)->screen.plane[Y]);
	while (i < sp->count)
	{
		sp->index = i;
		raycast_sprite(all, sp, &sp->img);
		i++;
	}
}
