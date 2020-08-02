/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:17:49 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/16 18:59:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	win_life(t_game **game)
{
	int i;
	int x;
	int y;

	i = 0;
	x = (int)(*game)->player.pos[X];
	y = (int)(*game)->player.pos[Y];
	while (i < (*game)->sp.count)
	{
		if (x == (int)(*game)->sp.coor[i][X] && y == (int)(*game)->sp.coor[i][Y]
		&& (*game)->sp.dead[i] == FALSE && (*game)->sp.type[i] == OBJ)
		{
			if ((*game)->life < 5)
				(*game)->life++;
			(*game)->sp.dead[i] = 1;
			(*game)->hit = 0;
		}
		i++;
	}
}

static void	lose_life(t_game **game, char c)
{
	int i;

	i = -1;
	if (c == OBJ1 && (*game)->loop[1] > 35 &&
	(*game)->life > 0 && (*game)->sp.dead[i] == FALSE)
	{
		(*game)->life--;
		(*game)->hit = 100;
		(*game)->loop[1] = 0;
	}
	else
	{
		while (++i < (*game)->sp.count)
		{
			if ((*game)->sp.see[i] == TRUE && (*game)->sp.type[i] == OBJ1
			&& (*game)->sp.dead[i] == FALSE && (*game)->loop[1] > 60
			&& (*game)->life > 0)
			{
				(*game)->hit = 100;
				(*game)->life--;
				(*game)->loop[1] = 0;
			}
		}
	}
}

void		manage_life(t_game **game, char c)
{
	win_life(game);
	lose_life(game, c);
	if ((*game)->loop[1] > 3)
		(*game)->hit = 0;
	if ((*game)->life == 0)
		draw_replay(game, &(*game)->lose_game, 3, 2);
}
