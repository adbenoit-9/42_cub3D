/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:58:53 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/02 23:59:57 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		init_sprite(t_game **game)
{
	(*game)->sp.count = 0;
	(*game)->sp.coor = NULL;
	(*game)->sp.pos = NULL;
	(*game)->sp.dead = NULL;
	(*game)->sp.see = NULL;
	(*game)->sp.dist = NULL;
	(*game)->sp.type = NULL;
	(*game)->sp.img.ptr = NULL;
	(*game)->sp_foe.img.ptr = NULL;
	(*game)->sp_dead.img.ptr = NULL;
}

static void	player_data(t_game **game, int dirx, int diry, double angle)
{
	(*game)->player.dir[X] = dirx;
	(*game)->player.dir[Y] = diry;
	(*game)->screen.plane[X] = ((*game)->player.dir[X] == 0) ? angle : 0;
	(*game)->screen.plane[Y] = ((*game)->player.dir[Y] == 0) ? angle : 0;
}

void		init_player_dir(t_game **game, char o)
{
	if (o == NORTH)
		player_data(game, 0, -1, 0.66);
	else if (o == SOUTH)
		player_data(game, 0, 1, -0.66);
	else if (o == EAST)
		player_data(game, 1, 0, 0.66);
	else if (o == WEST)
		player_data(game, -1, 0, -0.66);
}
