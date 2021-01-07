/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:22:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/03 13:35:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	pull_weapon(t_game **game)
{
	int i;

	if ((*game)->key.space == TRUE)
	{
		(*game)->loop[0] = 0;
		(*game)->weap.state = -1;
	}
	if ((*game)->weap.state < 3 && (*game)->loop[0] ==
							((*game)->weap.state + 1) * 4)
		(*game)->weap.state++;
	i = -1;
	while (++i < (*game)->sp.count)
	{
		if ((*game)->weap.state == 1 && (*game)->sp.see[i] == TRUE &&
			(*game)->sp.type[i] == OBJ1 && (*game)->sp.dead[i] == FALSE)
		{
			(*game)->nb_foe--;
			(*game)->sp.dead[i] = 1;
			(*game)->map[(int)(*game)->sp.coor[i][Y]][(int)
						(*game)->sp.coor[i][X]] = DEAD;
			break ;
		}
	}
}

static int	init_draw_weapon(t_game **game, t_draw *draw)
{
	pull_weapon(game);
	draw->h = abs((int)((*game)->r[Y] / 3));
	draw->w = abs((int)((*game)->r[Y] / 2));
	draw->start[X] = (*game)->r[X] / 2 - draw->w / 2;
	draw->end[X] = draw->start[X] + draw->w;
	draw->index[X] = 0;
	draw->start[X]--;
	return ((*game)->weap.state);
}

void		draw_weapon(t_game **game, t_tab_img *weap)
{
	t_draw	draw;
	int		state;
	int		col;
	int		i;

	state = init_draw_weapon(game, &draw);
	while (++draw.start[X] < draw.end[X])
	{
		draw.index[Y] = 0;
		draw.pix[X] = draw.index[X] * weap->dim[state][X] / draw.w;
		draw.start[Y] = (*game)->r[Y] - draw.h - 1;
		draw.end[Y] = draw.start[Y] + draw.h + 1;
		while (++draw.start[Y] < draw.end[Y])
		{
			draw.pix[Y] = draw.index[Y] * weap->dim[state][Y]
				/ draw.h;
			col = weap->data[state][(int)(weap->dim
					[state][X] * draw.pix[Y] + draw.pix[X])];
			i = draw.start[X] + (*game)->r[X] * draw.start[Y];
			if (col != 0)
				(*game)->img.data[i] = col;
			draw.index[Y]++;
		}
		draw.index[X]++;
	}
}
