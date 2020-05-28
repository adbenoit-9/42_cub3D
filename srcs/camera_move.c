/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:35:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 15:20:20 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turnleft(t_all **all)
{
	(*all)->player.old_dir[X] = (*all)->player.dir[X];
	(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED * -1) - (*all)->player.dir[Y] * sin(ROTSPEED * -1);
	(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED * -1) + (*all)->player.dir[Y] * cos(ROTSPEED * -1);
	(*all)->screen.old_plane[X] = (*all)->screen.plane[X];
	(*all)->screen.plane[X] = (*all)->screen.plane[X] * cos(ROTSPEED * -1) - (*all)->screen.plane[Y] * sin(ROTSPEED * -1);
	(*all)->screen.plane[Y] = (*all)->screen.old_plane[X] * sin(ROTSPEED * -1) + (*all)->screen.plane[Y] * cos(ROTSPEED * -1);
}

void	ft_turnright(t_all **all)
{
	(*all)->player.old_dir[X] = (*all)->player.dir[X];
	(*all)->player.dir[X] = (*all)->player.dir[X] * cos(ROTSPEED) - (*all)->player.dir[Y] * sin(ROTSPEED);
	(*all)->player.dir[Y] = (*all)->player.old_dir[X] * sin(ROTSPEED) + (*all)->player.dir[Y] * cos(ROTSPEED);
	(*all)->screen.old_plane[X] = (*all)->screen.plane[X];
	(*all)->screen.plane[X] = (*all)->screen.plane[X] * cos(ROTSPEED) - (*all)->screen.plane[Y] * sin(ROTSPEED);
    (*all)->screen.plane[Y] = (*all)->screen.old_plane[X] * sin(ROTSPEED) + (*all)->screen.plane[Y] * cos(ROTSPEED);
}

void	ft_move(t_all **all)
{
	if ((*all)->player.start_o == NORTH || (*all)->player.start_o == EAST)
	{
		(*all)->key.left == TRUE ? ft_turnleft(all) : FALSE;
		(*all)->key.right == TRUE ? ft_turnright(all) : FALSE;
		(*all)->key.a == TRUE ? ft_leftward(all) : FALSE;
		(*all)->key.d == TRUE ? ft_rightward(all) : FALSE;
	}
	else
	{
		(*all)->key.right == TRUE ? ft_turnleft(all) : FALSE;
		(*all)->key.left == TRUE ? ft_turnright(all) : FALSE;
		(*all)->key.d == TRUE ? ft_leftward(all) : FALSE;
		(*all)->key.a == TRUE ? ft_rightward(all) : FALSE;
	}
	(*all)->key.w == TRUE ? ft_forward(all) : FALSE;
	(*all)->key.s == TRUE ? ft_backward(all) : FALSE;
}