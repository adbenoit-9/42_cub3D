/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:17:32 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/30 18:18:48 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d_bonus.h"

int static	draw_heart_pixel(t_all **all, t_draw draw)
{
	int k;
	int col;

	draw.end[X] = draw.start[X] - draw.w;
	draw.index[X] = 0;
	while (draw.start[X] > draw.end[X])
	{
		draw.index[Y] = 0;
		draw.pix[X] = draw.index[X] * (*all)->bonus.heart.dim[X] / draw.w;
		draw.start[Y] = draw.h / 2;
		draw.end[Y] = draw.start[Y] + draw.h;
		while (draw.start[Y] < draw.end[Y])
		{
			draw.pix[Y] = draw.index[Y] * (*all)->bonus.heart.dim[Y] / draw.h;
			k = draw.start[X] + (*all)->r[X] * draw.start[Y];
			col = (*all)->bonus.heart.data[(int)
				((*all)->bonus.heart.dim[X] * draw.pix[Y] + draw.pix[X])];
			if (col != -16777216)
				(*all)->img.data[k] = col;
			draw.start[Y]++;
			draw.index[Y]++;
		}
		draw.index[X]++;
		draw.start[X]--;
	}
	return (draw.start[X]);
}

void		draw_hearts(t_all **all)
{
	t_draw  draw;
	int		i;

	manage_life(all, (*all)->bonus.map_c);
	draw.h = abs((int)((*all)->r[Y] / 20));
	draw.w = abs((int)((*all)->r[Y] / 20));
	draw.start[X] = (*all)->r[X] - draw.w / 2;
	i = 0;
	while (i <= (*all)->bonus.life)
	{
		draw.start[X] = draw_heart_pixel(all, draw);
		draw.start[X] -= draw.w / 2;
		i++;
	}   
}
