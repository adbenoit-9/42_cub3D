/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replay_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:19:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/06 22:07:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		draw_replay(t_all **all, t_img *im, int k1, int k2)
{
	t_draw	draw;
	int		col;

	draw.h = abs((int)((*all)->r[Y] / k1));
	draw.w = abs((int)((*all)->r[X] / k2));
	draw.start[X] = (*all)->r[X] / 2 - draw.w / 2 - 1;
	draw.end[X] = draw.start[X] + draw.w + 1;
	draw.index[X] = 0;
	while (++draw.start[X] < draw.end[X])
	{
		draw.index[Y] = 0;
		draw.pix[X] = draw.index[X] * im->dim[X] / draw.w;
		draw.start[Y] = (*all)->r[Y] / 2 - draw.h / 2 - 1;
		draw.end[Y] = draw.start[Y] + draw.h + 1;
		while (++draw.start[Y] < draw.end[Y])
		{
			draw.pix[Y] = draw.index[Y] * im->dim[Y] / draw.h;
			col = im->data[(int)(im->dim[X] * draw.pix[Y] + draw.pix[X])];
			if (col != -16777216)
				(*all)->img.data[draw.start[X] +
				(*all)->r[X] * draw.start[Y]] = col;
			draw.index[Y]++;
		}
		draw.index[X]++;
	}
}

static void	reinit_map(t_all **all)
{
	int	i;
	int	j;

	i = -1;
	while ((*all)->map[++i])
	{
		j = -1;
		while ((*all)->map[i][++j])
		{
			if ((*all)->map[i][j] == OPEN)
				(*all)->map[i][j] = DOOR;
			if ((*all)->map[i][j] == O_DOOR)
				(*all)->map[i][j] = WALL;
			if ((*all)->map[i][j] == DEAD)
			{
				(*all)->bonus.foe++;
				(*all)->map[i][j] = OBJ1;
			}
			if ((*all)->map[i][j] == (*all)->player.start_o)
			{
				(*all)->player.pos[X] = j + 0.5;
				(*all)->player.pos[Y] = i + 0.5;
			}
		}
	}
}

void		restart_game(t_all **all)
{
	int	i;

	reinit_map(all);
	init_player(all, (*all)->player.start_o);
	(*all)->screen.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	(*all)->screen.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
	(*all)->bonus.col = 0;
	(*all)->bonus.life = 5;
	(*all)->bonus.map_c = 0;
	i = 0;
	while (i < (*all)->sp.count)
	{
		(*all)->sp.see[i] = 0;
		(*all)->sp.dead[i] = 0;
		i++;
	}
}

int			ft_mouse(int button, int x, int y, t_all **all)
{
	int	start[2];
	int	end[2];

	if ((*all)->bonus.life == 0)
	{
		start[X] = (*all)->r[X] / 2 - abs((int)((*all)->r[X] / 3)) / 2;
		start[Y] = (*all)->r[Y] / 2 - abs((int)((*all)->r[Y] / 2)) / 2;
		end[X] = start[X] + abs((int)((*all)->r[Y] / 2));
		end[Y] = start[Y] + abs((int)((*all)->r[Y] / 2));
	}
	else
	{
		start[X] = 0;
		start[Y] = 0;
		end[X] = (*all)->r[X];
		end[Y] = (*all)->r[Y];
	}
	if (button == TRUE && ((*all)->bonus.life == 0 || (*all)->bonus.foe == 0)
	&& x > start[X] && x < end[X] && y > start[Y] && y < end[Y])
		restart_game(all);
	return (NO_ERR);
}
