/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:32:20 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:07:57 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_forward(t_all **all, t_player *p)
{
	char new_pos;

	new_pos = (*all)->map[(int)(p->pos[Y] + p->dir[Y]
		* MOVESPEED)][(int)(p->pos[X] + p->dir[X] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] += p->dir[X] * MOVESPEED;
		p->pos[Y] += p->dir[Y] * MOVESPEED;
	}
}

void	ft_leftward(t_all **all, t_player *p)
{
	char new_pos;

	new_pos = (*all)->map[(int)(p->pos[Y] - p->dir[X] *
		MOVESPEED)][(int)(p->pos[X] + p->dir[Y] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] += p->dir[Y] * MOVESPEED;
		p->pos[Y] -= p->dir[X] * MOVESPEED;
	}
}

void	ft_backward(t_all **all, t_player *p)
{
	char new_pos;

	new_pos = (*all)->map[(int)(p->pos[Y] - p->dir[Y] *
		MOVESPEED)][(int)(p->pos[X] - p->dir[X] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] -= p->dir[X] * MOVESPEED;
		p->pos[Y] -= p->dir[Y] * MOVESPEED;
	}
}

void	ft_rightward(t_all **all, t_player *p)
{
	char new_pos;

	new_pos = (*all)->map[(int)(p->pos[Y] + p->dir[X] *
		MOVESPEED)][(int)(p->pos[X] - p->dir[Y] * MOVESPEED)];
	(*all)->bonus.map_c = new_pos;
	if (new_pos != WALL && new_pos != DOOR &&
			new_pos != O_DOOR && new_pos != OBJ1)
	{
		p->pos[X] -= p->dir[Y] * MOVESPEED;
		p->pos[Y] += p->dir[X] * MOVESPEED;
	}
}
