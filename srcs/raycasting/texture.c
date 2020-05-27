/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:34:57 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/27 15:06:34 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	complete_text(t_all **all)
{
	(*all)->wall.dist[(*all)->grid.column] = wall_dist(all, &(*all)->wall);
	if ((*all)->wall.side % 2 == 0)
		(*all)->wall.hit = (*all)->player.map[Y] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[Y];
	else
		(*all)->wall.hit = (*all)->player.map[X] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[X];
	(*all)->wall.hit -= (int)(*all)->wall.hit;
	(*all)->text.pos[X] = (int)((*all)->wall.hit * (double)(*all)->text.dim[(*all)->wall.side][X]);
	if((*all)->wall.side == 0 && (*all)->wall.raydir[X] > 0)
		(*all)->text.pos[X] = (*all)->text.dim[(*all)->wall.side][X] - (*all)->text.pos[X] - 1;
	if((*all)->wall.side == 1 && (*all)->wall.raydir[Y] < 0)
		(*all)->text.pos[X] = (*all)->text.dim[(*all)->wall.side][X] - (*all)->text.pos[X] - 1;
}