/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replay_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 21:19:51 by adbenoit          #+#    #+#             */
/*   Updated: 2020/06/09 13:55:17 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		draw_replay(t_game **game, t_img *im, int k1, int k2)
{
	t_draw	draw;
	int		col;

	draw.h = abs((int)((*game)->r[Y] / k1));
	draw.w = abs((int)((*game)->r[X] / k2));
	draw.start[X] = (*game)->r[X] / 2 - draw.w / 2 - 1;
	draw.end[X] = draw.start[X] + draw.w + 1;
	draw.index[X] = 0;
	while (++draw.start[X] < draw.end[X])
	{
		draw.index[Y] = 0;
		draw.pix[X] = draw.index[X] * im->dim[X] / draw.w;
		draw.start[Y] = (*game)->r[Y] / 2 - draw.h / 2 - 1;
		draw.end[Y] = draw.start[Y] + draw.h + 1;
		while (++draw.start[Y] < draw.end[Y])
		{
			draw.pix[Y] = draw.index[Y] * im->dim[Y] / draw.h;
			col = im->data[(int)(im->dim[X] * draw.pix[Y] + draw.pix[X])];
			if (col != -16777216)
				(*game)->img.data[draw.start[X] +
				(*game)->r[X] * draw.start[Y]] = col;
			draw.index[Y]++;
		}
		draw.index[X]++;
	}
}

static void	reinit_map(t_game **game)
{
	int	i;
	int	j;

	i = -1;
	while ((*game)->map[++i])
	{
		j = -1;
		while ((*game)->map[i][++j])
		{
			if ((*game)->map[i][j] == OPEN)
				(*game)->map[i][j] = DOOR;
			if ((*game)->map[i][j] == O_DOOR)
				(*game)->map[i][j] = WALL;
			if ((*game)->map[i][j] == DEAD)
			{
				(*game)->nb_foe++;
				(*game)->map[i][j] = OBJ1;
			}
			if ((*game)->map[i][j] == (*game)->player.start_o)
			{
				(*game)->player.pos[X] = j + 0.5;
				(*game)->player.pos[Y] = i + 0.5;
			}
		}
	}
}

void		restart_game(t_game **game)
{
	int	i;

	reinit_map(game);
	init_player_dir(game, (*game)->player.start_o);
	(*game)->screen.plane[X] = ((*game)->player.dir[X] == 0) ? 0.66 : 0;
	(*game)->screen.plane[Y] = ((*game)->player.dir[Y] == 0) ? 0.66 : 0;
	(*game)->hit = 0;
	(*game)->life = 5;
	(*game)->map_c = 0;
	i = 0;
	while (i < (*game)->sp.count)
	{
		(*game)->sp.see[i] = 0;
		(*game)->sp.dead[i] = 0;
		i++;
	}
}

int			ft_mouse(int button, int x, int y, t_game **game)
{
	int	start[2];
	int	end[2];

	if ((*game)->life == 0)
	{
		start[X] = (*game)->r[X] / 2 - abs((int)((*game)->r[X] / 3)) / 2;
		start[Y] = (*game)->r[Y] / 2 - abs((int)((*game)->r[Y] / 2)) / 2;
		end[X] = start[X] + abs((int)((*game)->r[Y] / 2));
		end[Y] = start[Y] + abs((int)((*game)->r[Y] / 2));
	}
	else
	{
		start[X] = 0;
		start[Y] = 0;
		end[X] = (*game)->r[X];
		end[Y] = (*game)->r[Y];
	}
	if (button == TRUE && ((*game)->life == 0 || (*game)->nb_foe == 0)
	&& x > start[X] && x < end[X] && y > start[Y] && y < end[Y])
		restart_game(game);
	return (NO_ERR);
}
