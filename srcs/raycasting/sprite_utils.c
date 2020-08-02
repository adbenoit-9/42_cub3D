/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:45:49 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/01 19:49:23 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite(t_sprite *sp)
{
	double	tmp;
	int		i;
	int		j;

	j = -1;
	while (++j < sp->count)
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
	}
}

void	add_dist(t_game **game, t_sprite *sp, void (*sort)(t_sprite *))
{
	int i;

	i = 0;
	while (i < sp->count)
	{
		sp->dist[i] = pow((*game)->player.pos[X] - sp->coor[i][X], 2) +
					pow((*game)->player.pos[Y] - sp->coor[i][Y], 2);
		i++;
	}
	sort(sp);
}

void	draw_sprite(t_game **game, t_sprite *sp)
{
	int		i;

	i = 0;
	add_dist(game, sp, sort_sprite);
	(*game)->invdet = 1.0 / ((*game)->screen.plane[X] * (*game)->player.dir[Y] -
					(*game)->player.dir[X] * (*game)->screen.plane[Y]);
	while (i < sp->count)
	{
		sp->index = i;
		raycast_sprite(game, sp, &sp->img);
		i++;
	}
}
