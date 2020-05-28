/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:57:19 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 19:00:52 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pull_weapon(t_all **all)
{
	int i;

	if ((*all)->key.space == TRUE)
	{
		(*all)->bonus.loop = 0;
		(*all)->bonus.pull = -1;
	}
	if ((*all)->bonus.pull < 3 && (*all)->bonus.loop == ((*all)->bonus.pull + 1) * 4)
		(*all)->bonus.pull++;
	i = 0;
	while (i < (*all)->sp.count)
	{
		if ((*all)->bonus.pull == 1 && (*all)->sp.see[i] == TRUE && (*all)->sp.type[i] == OBJ1 && (*all)->sp.dead[i] == FALSE)
		{
			(*all)->bonus.foe--;
			(*all)->sp.dead[i] = 1;
			(*all)->map[(int)(*all)->sp.coor[i][Y]][(int)(*all)->sp.coor[i][X]] = DEAD;
			break ;
		}
		i++;
	}
	if ((*all)->bonus.foe == 0)
        draw_replay(all, &(*all)->bonus.win, 1, 1);
}

static int	init_draw_weapon(t_all **all, t_draw *draw)
{
	pull_weapon(all);
	draw->h = abs((int)((*all)->r[Y] / 3));
    draw->w = abs((int)((*all)->r[Y] / 2));
    draw->start[X] = (*all)->r[X] / 2 - draw->w / 2;
    draw->end[X] = draw->start[X] + draw->w;
    draw->index[X] = 0;
	return ((*all)->bonus.pull);
}
void    	draw_weapon(t_all **all)
{
	t_draw	draw;
	int		pull;

	pull = init_draw_weapon(all, &draw);
	while (draw.start[X] < draw.end[X])
	{
        draw.index[Y] = 0;
        draw.pix[X] = draw.index[X] * (*all)->bonus.weap.dim[pull][X] / draw.w;
		draw.start[Y] = (*all)->r[Y] - draw.h;
        draw.end[Y] = draw.start[Y] + draw.h;
		while (draw.start[Y] < draw.end[Y])
		{
            draw.pix[Y] = draw.index[Y] * (*all)->bonus.weap.dim[pull][Y] / draw.h;
		    if ((*all)->bonus.weap.data[pull][(int)((*all)->bonus.weap.dim[pull][X] * draw.pix[Y] + draw.pix[X])] != -16777216)
			    (*all)->img.data[draw.start[X] + (*all)->r[X] * draw.start[Y]] = (*all)->bonus.weap.data[pull]
						[(int)((*all)->bonus.weap.dim[pull][X] * draw.pix[Y] + draw.pix[X])];
		    draw.start[Y]++;
            draw.index[Y]++;
		}
        draw.index[X]++;
		draw.start[X]++;
    }
}
