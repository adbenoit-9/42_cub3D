/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:35:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/02 16:15:37 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turnleft(t_all **all)
{
	(*all)->player.old_dir[X] = (*all)->player.dir[X];
	(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED * -1) - (*all)->player.dir[Y] * sin(ROTSPEED * -1);
	(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED * -1) + (*all)->player.dir[Y] * cos(ROTSPEED * -1);
	(*all)->grid.old_plane[X] = (*all)->grid.plane[X];
	(*all)->grid.plane[X] = (*all)->grid.plane[X] * cos(ROTSPEED * -1) - (*all)->grid.plane[Y] * sin(ROTSPEED * -1);
	(*all)->grid.plane[Y] = (*all)->grid.old_plane[X] * sin(ROTSPEED * -1) + (*all)->grid.plane[Y] * cos(ROTSPEED * -1);
}

void	ft_turnright(t_all **all)
{
	(*all)->player.old_dir[X] = (*all)->player.dir[X];
	(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED) - (*all)->player.dir[Y] * sin(ROTSPEED);
	(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED) + (*all)->player.dir[Y] * cos(ROTSPEED);
	(*all)->grid.old_plane[X] = (*all)->grid.plane[X];
	(*all)->grid.plane[X] = (*all)->grid.plane[X] * cos(ROTSPEED) - (*all)->grid.plane[Y] * sin(ROTSPEED);
    (*all)->grid.plane[Y] = (*all)->grid.old_plane[X] * sin(ROTSPEED) + (*all)->grid.plane[Y] * cos(ROTSPEED);
}

void	ft_forward(t_all **all)
{
	if((*all)->map[(int)((*all)->player.map[Y] + (*all)->player.dir[Y] * MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[X] * MOVESPEED)] != WALL)
	{
		(*all)->player.map[X] += (*all)->player.dir[X] * MOVESPEED;
		(*all)->player.map[Y] += (*all)->player.dir[Y] * MOVESPEED;
		//printf("(%d, %f)\n", (int)4.5, (*all)->player.map[Y]);
	}
}

void	ft_leftward(t_all **all)
{
	if((*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[X] * MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[Y] * MOVESPEED)] != WALL)
	{
		(*all)->player.map[X] += (*all)->player.dir[Y] * MOVESPEED;
		(*all)->player.map[Y] -= (*all)->player.dir[X] * MOVESPEED;
	}
}

void	ft_backward(t_all **all)
{
	if((*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[Y] * MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[X] * MOVESPEED)] != WALL)
	{
		(*all)->player.map[X] -= (*all)->player.dir[X] * MOVESPEED;
		(*all)->player.map[Y] -= (*all)->player.dir[Y] * MOVESPEED;
	}
}

void	ft_rightward(t_all **all)
{
	if((*all)->map[(int)(int)((*all)->player.map[Y] + (*all)->player.dir[X] * MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[Y] * MOVESPEED)] != WALL)
	{
		(*all)->player.map[X] -= (*all)->player.dir[Y] * MOVESPEED;
		(*all)->player.map[Y] += (*all)->player.dir[X] * MOVESPEED;
	}
}

void	ft_move(t_all **all)
{
	(*all)->key.left == 1 ? ft_turnleft(all) : 0;
	(*all)->key.right == 1 ? ft_turnright(all) : 0;
	(*all)->key.w == 1 ? ft_forward(all) : 0;
	(*all)->key.a == 1 ? ft_leftward(all) : 0;
	(*all)->key.d == 1 ? ft_rightward(all) : 0;
	(*all)->key.s == 1 ? ft_backward(all) : 0;
}