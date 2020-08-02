/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:15:32 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/01 18:00:22 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_drawing(t_game **game, int *start, int *end, t_tab_img *text)
{
	int i;
	int	side;

	i = (*game)->screen.x;
	side = (*game)->wall.side;
	(*game)->wall.dist[i] = set_wall_dist(game, &(*game)->wall);
	if (side % 2 == 0)
		(*game)->wall.hit = (*game)->player.pos[Y] + (*game)->wall.dist[i]
							* (*game)->wall.raydir[Y];
	else
		(*game)->wall.hit = (*game)->player.pos[X] + (*game)->wall.dist[i] *
							(*game)->wall.raydir[X];
	(*game)->wall.hit -= (int)(*game)->wall.hit;
	text->pix[X] = (int)((*game)->wall.hit * text->dim[side][X]) * 1.0;
	if (side == 0 && (*game)->wall.raydir[X] > 0)
		text->pix[X] = text->dim[side][X] - text->pix[X] - 1;
	if (side == 1 && (*game)->wall.raydir[Y] < 0)
		text->pix[X] = text->dim[side][X] - text->pix[X] - 1;
	(*game)->wall.slice_h = (*game)->r[Y] / (*game)->wall.dist[i];
	*start = -1 * (*game)->wall.slice_h / 2 + (*game)->r[Y] / 2;
	if (*start < 0)
		*start = 0;
	*end = (*game)->wall.slice_h / 2 + (*game)->r[Y] / 2;
	if (*end >= (*game)->r[Y] || *end < 0)
		*end = (*game)->r[Y] - 1;
}

void	draw_wall_pixel(t_game **game, t_tab_img *text, int i, int side)
{
	int		end;
	int		start;
	int		k;
	double	step;
	double	pix;

	init_drawing(game, &start, &end, text);
	step = 1.0 * text->dim[side][Y] / (*game)->wall.slice_h;
	pix = (start - (*game)->r[Y] / 2 + (*game)->wall.slice_h / 2) * step;
	k = -1;
	while (++k < start)
		(*game)->img.data[i + (*game)->r[X] * k] = (*game)->c;
	while (start < end)
	{
		text->pix[Y] = (int)pix;
		pix += step;
		(*game)->img.data[i + (*game)->r[X] * start] =
			text->data[side][(int)(text->dim[side][X] *
			text->pix[Y] + text->pix[X])];
		start++;
	}
	k = start - 1;
	while (++k < (*game)->r[Y])
		(*game)->img.data[i + (*game)->r[X] * k] = (*game)->f;
}

void	draw_wall(t_game **game)
{
	while ((*game)->screen.x < (*game)->r[X])
	{
		init_wall(game, &(*game)->wall);
		set_side_dist(game, &(*game)->wall);
		set_wall_side(game);
		draw_wall_pixel(game, &(*game)->text, (*game)->screen.x,
						(*game)->wall.side);
		(*game)->screen.x++;
	}
}
