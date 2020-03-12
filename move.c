/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:35:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/12 20:02:28 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_view(t_all **all)
{
	if ((*all)->key.left == 1)
	{
		(*all)->player.old_dir[X] = (*all)->player.dir[X];
		(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED * -1) - (*all)->player.dir[Y] * sin(ROTSPEED * -1);
		(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED * -1) + (*all)->player.dir[Y] * cos(ROTSPEED * -1);
		(*all)->grid.old_plane[X] = (*all)->grid.plane[X];
		(*all)->grid.plane[X] = (*all)->grid.plane[X] * cos(ROTSPEED * -1) - (*all)->grid.plane[Y] * sin(ROTSPEED * -1);
      	(*all)->grid.plane[Y] = (*all)->grid.old_plane[X] * sin(ROTSPEED * -1) + (*all)->grid.plane[Y] * cos(ROTSPEED * -1);
	}
	if ((*all)->key.right == 1)
	{
		(*all)->player.old_dir[X] = (*all)->player.dir[X];
		(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED) - (*all)->player.dir[Y] * sin(ROTSPEED);
		(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED) + (*all)->player.dir[Y] * cos(ROTSPEED);
		(*all)->grid.old_plane[X] = (*all)->grid.plane[X];
		(*all)->grid.plane[X] = (*all)->grid.plane[X] * cos(ROTSPEED) - (*all)->grid.plane[Y] * sin(ROTSPEED);
      	(*all)->grid.plane[Y] = (*all)->grid.old_plane[X] * sin(ROTSPEED) + (*all)->grid.plane[Y] * cos(ROTSPEED);
	}
}

void	direct_wa(t_all **all)
{
	if ((*all)->key.w == 1)
    {
		if((*all)->map[(int)((*all)->player.map[Y] + (*all)->player.dir[Y] * MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[X] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] += (*all)->player.dir[X] * MOVESPEED;
			(*all)->player.map[Y] += (*all)->player.dir[Y] * MOVESPEED;
		}
	}
	if ((*all)->key.a == 1)
    {
		if((*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[X] * MOVESPEED)][(int)((*all)->player.map[X] + (*all)->player.dir[Y] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] += (*all)->player.dir[Y] * MOVESPEED;
			(*all)->player.map[Y] -= (*all)->player.dir[X] * MOVESPEED;
		}
    }
}

void	direct_sd(t_all **all)
{
	if ((*all)->key.s == 1)
    {
		if((*all)->map[(int)((*all)->player.map[Y] - (*all)->player.dir[Y] * MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[X] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] -= (*all)->player.dir[X] * MOVESPEED;
			(*all)->player.map[Y] -= (*all)->player.dir[Y] * MOVESPEED;
		}
	}
	if ((*all)->key.d == 1)
    {
		if((*all)->map[(int)(int)((*all)->player.map[Y] + (*all)->player.dir[X] * MOVESPEED)][(int)((*all)->player.map[X] - (*all)->player.dir[Y] * MOVESPEED)] != WALL)
		{
			(*all)->player.map[X] -= (*all)->player.dir[Y] * MOVESPEED;
			(*all)->player.map[Y] += (*all)->player.dir[X] * MOVESPEED;
		}
    }
}

void	ft_move(t_all **all)
{
	ft_view(all);
	direct_wa(all);
	direct_sd(all);
	create_image(all);
}

int		ft_deal_key(int key, t_all **all)
{
	if (key == LEFT)
		(*all)->key.left = 0;
	if (key == RIGHT)
		(*all)->key.right = 0;
	if (key == KEY_W)
		(*all)->key.w = 0;
	if (key == KEY_A)
		(*all)->key.a = 0;
	if (key == KEY_S)
		(*all)->key.s = 0;
	if (key == KEY_D)
		(*all)->key.d = 0;
	return(0);
}