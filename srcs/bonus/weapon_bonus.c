/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:22:03 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/07 18:21:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	pull_weapon(t_all **all)
{
	int i;

	if ((*all)->key.space == TRUE)
	{
		(*all)->bonus.loop[0] = 0;
		(*all)->bonus.weap.state = -1;
	}
	if ((*all)->bonus.weap.state < 3 && (*all)->bonus.loop[0] ==
							((*all)->bonus.weap.state + 1) * 4)
		(*all)->bonus.weap.state++;
	i = -1;
	while (++i < (*all)->sp.count)
	{
		if ((*all)->bonus.weap.state == 1 && (*all)->sp.see[i] == TRUE &&
			(*all)->sp.type[i] == OBJ1 && (*all)->sp.dead[i] == FALSE)
		{
			(*all)->bonus.foe--;
			(*all)->sp.dead[i] = 1;
			(*all)->map[(int)(*all)->sp.coor[i][Y]][(int)
						(*all)->sp.coor[i][X]] = DEAD;
			break ;
		}
	}
	if ((*all)->bonus.foe == 0)
		draw_replay(all, &(*all)->bonus.win_game, 1, 1);
}

static int	init_draw_weapon(t_all **all, t_draw *draw)
{
	pull_weapon(all);
	draw->h = abs((int)((*all)->r[Y] / 3));
	draw->w = abs((int)((*all)->r[Y] / 2));
	draw->start[X] = (*all)->r[X] / 2 - draw->w / 2;
	draw->end[X] = draw->start[X] + draw->w;
	draw->index[X] = 0;
	draw->start[X]--;
	return ((*all)->bonus.weap.state);
}

void		draw_weapon(t_all **all, t_tab_img *weap)
{
	t_draw	draw;
	int		pull;
	int		col;
	int		i;

	pull = init_draw_weapon(all, &draw);
	while (++draw.start[X] < draw.end[X])
	{
		draw.index[Y] = 0;
		draw.pix[X] = draw.index[X] * weap->dim[pull][X] / draw.w;
		draw.start[Y] = (*all)->r[Y] - draw.h - 1;
		draw.end[Y] = draw.start[Y] + draw.h + 1;
		while (++draw.start[Y] < draw.end[Y])
		{
			draw.pix[Y] = draw.index[Y] * weap->dim[pull][Y]
				/ draw.h;
			col = weap->data[pull][(int)(weap->dim
					[pull][X] * draw.pix[Y] + draw.pix[X])];
			i = draw.start[X] + (*all)->r[X] * draw.start[Y];
			if (col != -16777216)
				(*all)->img.data[i] = col;
			draw.index[Y]++;
		}
		draw.index[X]++;
	}
}
