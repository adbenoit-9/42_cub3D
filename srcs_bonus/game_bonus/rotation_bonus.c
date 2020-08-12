/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:35:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:42:12 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_turnleft(t_game **game)
{
	(*game)->player.old_dir[X] = (*game)->player.dir[X];
	(*game)->player.dir[X] = (*game)->player.dir[X] * cos(ROTSPEED * -1) -
							(*game)->player.dir[Y] * sin(ROTSPEED * -1);
	(*game)->player.dir[Y] = (*game)->player.old_dir[X] * sin(ROTSPEED * -1) +
							(*game)->player.dir[Y] * cos(ROTSPEED * -1);
	(*game)->screen.old_plane[X] = (*game)->screen.plane[X];
	(*game)->screen.plane[X] = (*game)->screen.plane[X] * cos(ROTSPEED * -1) -
								(*game)->screen.plane[Y] * sin(ROTSPEED * -1);
	(*game)->screen.plane[Y] = (*game)->screen.old_plane[X] * sin(ROTSPEED * -1)
								+ (*game)->screen.plane[Y] * cos(ROTSPEED * -1);
}

void	ft_turnright(t_game **game)
{
	(*game)->player.old_dir[X] = (*game)->player.dir[X];
	(*game)->player.dir[X] = (*game)->player.dir[X] * cos(ROTSPEED) -
							(*game)->player.dir[Y] * sin(ROTSPEED);
	(*game)->player.dir[Y] = (*game)->player.old_dir[X] * sin(ROTSPEED) +
							(*game)->player.dir[Y] * cos(ROTSPEED);
	(*game)->screen.old_plane[X] = (*game)->screen.plane[X];
	(*game)->screen.plane[X] = (*game)->screen.plane[X] * cos(ROTSPEED) -
								(*game)->screen.plane[Y] * sin(ROTSPEED);
	(*game)->screen.plane[Y] = (*game)->screen.old_plane[X] * sin(ROTSPEED) +
								(*game)->screen.plane[Y] * cos(ROTSPEED);
}

void	ft_move(t_game **game)
{
	(*game)->key.left == TRUE ? ft_turnleft(game) : FALSE;
	(*game)->key.right == TRUE ? ft_turnright(game) : FALSE;
	(*game)->key.a == TRUE ? ft_leftward(game, &(*game)->player) : FALSE;
	(*game)->key.d == TRUE ? ft_rightward(game, &(*game)->player) : FALSE;
	(*game)->key.w == TRUE ? ft_forward(game, &(*game)->player) : FALSE;
	(*game)->key.s == TRUE ? ft_backward(game, &(*game)->player) : FALSE;
}
