/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:15:32 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 17:40:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void static	init_drawing(t_all **all, int *start, int *end, t_tab_img *t)
{
	int i;

	i = (*all)->screen.column;
	(*all)->wall.dist[i] = set_wall_dist(all, &(*all)->wall);
	if ((*all)->wall.side % 2 == 0)
		(*all)->wall.hit = (*all)->player.map[Y] + (*all)->wall.dist[i] * (*all)->wall.raydir[Y];
	else
		(*all)->wall.hit = (*all)->player.map[X] + (*all)->wall.dist[i] * (*all)->wall.raydir[X];
	(*all)->wall.hit -= (int)(*all)->wall.hit;
	t->pos[X] = (int)((*all)->wall.hit * (double)t->dim[(*all)->wall.side][X]);
	if((*all)->wall.side == 0 && (*all)->wall.raydir[X] > 0)
		t->pos[X] = t->dim[(*all)->wall.side][X] - t->pos[X] - 1;
	if((*all)->wall.side == 1 && (*all)->wall.raydir[Y] < 0)
		t->pos[X] = t->dim[(*all)->wall.side][X] - t->pos[X] - 1;
	(*all)->wall.slice_h = (*all)->r[Y] / (*all)->wall.dist[i];
	*start = -1 * (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
	if (*start < 0)
		*start = 0;
	*end = (*all)->wall.slice_h / 2 + (*all)->r[Y] / 2;
	if (*end >= (*all)->r[Y] || *end < 0)
		*end = (*all)->r[Y] - 1;
}

void		draw_wall_pixel(t_all **all, t_tab_img *text, int i)
{
	int		end;
	int		start;
	int		k;
	double	step;
	double	textpos;

	init_drawing(all, &start, &end, text);
	step = 1.0 * text->dim[(*all)->wall.side][Y] / (*all)->wall.slice_h;
	textpos = (start - (*all)->r[Y] / 2 + (*all)->wall.slice_h / 2) * step;
	k = -1;
	while (++k < start)
		(*all)->img.data[i + (*all)->r[X] * k] = (*all)->c + (*all)->bonus.col;
	while (start < end)
	{
		text->pos[Y] = (int)textpos;
		textpos += step;
		(*all)->img.data[i + (*all)->r[X] * start] = text->data[(*all)->wall.side]
			[(int)(text->dim[(*all)->wall.side][X] * text->pos[Y] + text->pos[X])] + (*all)->bonus.col;
		start++;
	}
	k = start - 1;
	while (++k < (*all)->r[Y])
		(*all)->img.data[i + (*all)->r[X] * k] = (*all)->f + (*all)->bonus.col;
}

void	draw_wall(t_all **all)
{
	while ((*all)->screen.column < (*all)->r[X])
	{
		init_wall(all, &(*all)->wall);
		set_side_dist(all, &(*all)->wall);
		set_wall_side(all);
		draw_wall_pixel(all, &(*all)->text, (*all)->screen.column);
		(*all)->screen.column++;
	}
}
