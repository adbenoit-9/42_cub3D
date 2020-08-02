/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:32:20 by adbenoit          #+#    #+#             */
/*   Updated: 2020/07/05 20:18:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_forward(t_game **game, t_player *p)
{
	char new_pos;

	new_pos = (*game)->map[(int)(p->pos[Y] + p->dir[Y]
		* MOVESPEED)][(int)(p->pos[X] + p->dir[X] * MOVESPEED)];
	(*game)->map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] += p->dir[X] * MOVESPEED;
		p->pos[Y] += p->dir[Y] * MOVESPEED;
	}
}

void	ft_leftward(t_game **game, t_player *p)
{
	char new_pos;

	new_pos = (*game)->map[(int)(p->pos[Y] - p->dir[X] *
		MOVESPEED)][(int)(p->pos[X] + p->dir[Y] * MOVESPEED)];
	(*game)->map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] += p->dir[Y] * MOVESPEED;
		p->pos[Y] -= p->dir[X] * MOVESPEED;
	}
}

void	ft_backward(t_game **game, t_player *p)
{
	char new_pos;

	new_pos = (*game)->map[(int)(p->pos[Y] - p->dir[Y] *
		MOVESPEED)][(int)(p->pos[X] - p->dir[X] * MOVESPEED)];
	(*game)->map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] -= p->dir[X] * MOVESPEED;
		p->pos[Y] -= p->dir[Y] * MOVESPEED;
	}
}

void	ft_rightward(t_game **game, t_player *p)
{
	char new_pos;

	new_pos = (*game)->map[(int)(p->pos[Y] + p->dir[X] *
		MOVESPEED)][(int)(p->pos[X] - p->dir[Y] * MOVESPEED)];
	(*game)->map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] -= p->dir[Y] * MOVESPEED;
		p->pos[Y] += p->dir[X] * MOVESPEED;
	}
}
