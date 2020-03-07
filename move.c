/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:35:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/06 17:40:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_view(int key, t_all **all)
{
	if (key == LEFT)
	{
		(*all)->player.old_dir[X] = (*all)->player.dir[X];
		(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED * -1) - (*all)->player.dir[Y] * sin(ROTSPEED * -1);
		(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED * -1) + (*all)->player.dir[Y] * cos(ROTSPEED * -1);
		(*all)->grid.old_plane[X] = (*all)->grid.plane[X];
		(*all)->grid.plane[X] = (*all)->grid.plane[X] * cos(ROTSPEED * -1) - (*all)->grid.plane[Y] * sin(ROTSPEED * -1);
      	(*all)->grid.plane[Y] = (*all)->grid.old_plane[X] * sin(ROTSPEED * -1) + (*all)->grid.plane[Y] * cos(ROTSPEED * -1);
	}
	if (key == RIGHT)
	{
		(*all)->player.old_dir[X] = (*all)->player.dir[X];
		(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED) - (*all)->player.dir[Y] * sin(ROTSPEED);
		(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED) + (*all)->player.dir[Y] * cos(ROTSPEED);
		(*all)->grid.old_plane[X] = (*all)->grid.plane[X];
		(*all)->grid.plane[X] = (*all)->grid.plane[X] * cos(ROTSPEED) - (*all)->grid.plane[Y] * sin(ROTSPEED);
      	(*all)->grid.plane[Y] = (*all)->grid.old_plane[X] * sin(ROTSPEED) + (*all)->grid.plane[Y] * cos(ROTSPEED);
	}
}

void	direct_WA(int key, t_all **all)
{
	if (key == KEY_W)
    {
		if((*all)->map[(int)((*all)->player.map[Y] + (*all)->player.dir[Y] * MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[X] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] += (*all)->player.dir[X] * MOVESPEED;
			(*all)->player.map[Y] += (*all)->player.dir[Y] * MOVESPEED;
		}
	}
	if (key == KEY_A)
    {
		if((*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[X] * MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[Y] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] += (*all)->player.dir[Y] * MOVESPEED;
			(*all)->player.map[Y] -= (*all)->player.dir[X] * MOVESPEED;
		}
    }
}

void	direct_SD(int key, t_all **all)
{
	if (key == KEY_S)
    {
		if((*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[Y] * MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[X] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] -= (*all)->player.dir[X] * MOVESPEED;
			(*all)->player.map[Y] -= (*all)->player.dir[Y] * MOVESPEED;
		}
	}
	if (key == KEY_D)
    {
		if((*all)->map[(int)(int)((*all)->player.map[Y] + (*all)->player.dir[X] * MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[Y] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] -= (*all)->player.dir[Y] * MOVESPEED;
			(*all)->player.map[Y] += (*all)->player.dir[X] * MOVESPEED;
		}
    }
}

int		ft_deal_key(int key, t_all **all)
{
	if (key == ESC)
	{
		mlx_destroy_window((*all)->mlx, (*all)->win);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_view(key, all);
		direct_WA(key, all);
		direct_SD(key, all);
    	create_image(all);
	}
	return(0);
}