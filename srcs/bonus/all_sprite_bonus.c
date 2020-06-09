/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:16:20 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/08 22:58:06 by adbenoit         ###   ########.fr       */
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

static void	sort_game_sprite(t_sprite *sp)
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

void		set_sprite_coor(t_game **game, char *line, int i)
{
	int	size;

	if (line[i] == OBJ || line[i] == OBJ1)
	{
		(*game)->sp.count++;
		size = (*game)->sp.count;
		if (!((*game)->sp.coor = realloc_doub((*game)->sp.coor, size)))
			exit_error(game, line, MAL_ERR);
		if (!((*game)->sp.type = realloc((*game)->sp.type, size + 1)))
			exit_error(game, NULL, MAL_ERR);
		(*game)->sp.coor[size - 1][X] = i + 0.5;
		(*game)->sp.coor[size - 1][Y] = (*game)->map_size - 1 + 0.5;
		(*game)->sp.type[size - 1] = line[i];
		if (line[i] == OBJ1)
			(*game)->nb_foe++;
		(*game)->sp.type[size] = 0;
	}
}

void		draw_all_sprites(t_game **game, t_sprite *sp)
{
	int		i;

	i = 0;
	add_dist(game, sp, sort_game_sprite);
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
