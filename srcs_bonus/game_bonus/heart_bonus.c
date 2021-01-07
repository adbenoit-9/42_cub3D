/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:17:32 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 15:26:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_heart_pixel(t_game **game, t_draw *draw)
{
	int k;
	int col;

	draw->end[X] = draw->start[X] - draw->w;
	draw->index[X] = -1;
	while (draw->start[X] > draw->end[X])
	{
		draw->index[Y] = 0;
		draw->pix[X] = ++draw->index[X] * (*game)->heart.dim[X] / draw->w;
		draw->start[Y] = draw->h / 2;
		draw->end[Y] = draw->start[Y] + draw->h;
		while (draw->start[Y] < draw->end[Y])
		{
			draw->pix[Y] = draw->index[Y] *
						(*game)->heart.dim[Y] / draw->h;
			k = draw->start[X] + (*game)->r[X] * draw->start[Y];
			col = (*game)->heart.data[(int)
				((*game)->heart.dim[X] * draw->pix[Y] + draw->pix[X])];
			if (col != 0)
				(*game)->img.data[k] = col;
			draw->start[Y]++;
			draw->index[Y]++;
		}
		draw->start[X]--;
	}
}

void	draw_hearts(t_game **game)
{
	t_draw	draw;
	int		i;

	manage_life(game, (*game)->map_c);
	draw.h = abs((int)((*game)->r[Y] / 20));
	draw.w = abs((int)((*game)->r[Y] / 20));
	draw.start[X] = (*game)->r[X] - draw.w / 2;
	i = 0;
	while (i < (*game)->life)
	{
		draw_heart_pixel(game, &draw);
		draw.start[X] -= draw.w / 2;
		i++;
	}
}
