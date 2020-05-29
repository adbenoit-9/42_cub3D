/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:45:49 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 16:46:34 by adbenoit         ###   ########.fr       */
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
