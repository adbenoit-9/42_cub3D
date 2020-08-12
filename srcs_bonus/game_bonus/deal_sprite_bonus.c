/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:01:22 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 15:00:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	switch_sprite(t_sprite *sp, int i)
{
	double	tmp;

	tmp = sp->dist[i];
	sp->dist[i] = sp->dist[i + 1];
	sp->dist[i + 1] = tmp;
	tmp = sp->coor[i][X];
	sp->coor[i][X] = sp->coor[i + 1][X];
	sp->coor[i + 1][X] = tmp;
	tmp = sp->coor[i][Y];
	sp->coor[i][Y] = sp->coor[i + 1][Y];
	sp->coor[i + 1][Y] = tmp;
	tmp = sp->type[i];
	sp->type[i] = sp->type[i + 1];
	sp->type[i + 1] = tmp;
	tmp = sp->dead[i];
	sp->dead[i] = sp->dead[i + 1];
	sp->dead[i + 1] = tmp;
	tmp = sp->see[i];
	sp->see[i] = sp->see[i + 1];
	sp->see[i + 1] = tmp;
}

static void	sort_sprite_bonus(t_sprite *sp)
{
	int i;
	int j;

	j = 0;
	while (j < sp->count)
	{
		i = 0;
		while (i < sp->count - 1)
		{
			if (sp->dist[i] < sp->dist[i + 1])
				switch_sprite(sp, i);
			i++;
		}
		j++;
	}
}

void		draw_sprite(t_game **game, t_sprite *sp)
{
	int		i;

	i = 0;
	add_dist(game, sp, sort_sprite_bonus);
	(*game)->invdet = 1.0 / ((*game)->screen.plane[X] * (*game)->player.dir[Y] -
	(*game)->player.dir[X] * (*game)->screen.plane[Y]);
	while (i < sp->count)
	{
		sp->index = i;
		if (sp->dead[i] == FALSE && sp->type[i] == OBJ)
			raycast_sprite(game, sp, &sp->img);
		else if (sp->dead[i] == FALSE && sp->type[i] == OBJ1)
			raycast_sprite(game, sp, &(*game)->sp_foe.img);
		else if (sp->dead[i] == TRUE && sp->type[i] == OBJ1)
			raycast_sprite(game, sp, &(*game)->sp_dead.img);
		i++;
	}
}
