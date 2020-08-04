/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 22:55:09 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/04 23:01:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	vertical_axis(t_game **game, int len, int k)
{
	int start;
	int x;
	int end;
	int mid;

	start = (*game)->r[Y] / 2;
	mid = (*game)->r[Y] / 2;
	x = (*game)->r[X] / 2;
	end = start + len / 2;
	start -= len / 2;
	while (start < end)
	{
		if (start < mid - len / 10 || start > mid + len / 10)
			(*game)->img.data[x + k + (*game)->r[X] * start] = ft_rgb(0, 0, 0);
		start++;
	}
}

static void	horizontal_axis(t_game **game, int len, int k)
{
	int start;
	int y;
	int end;
	int	mid;
	int	black;

	y = (*game)->r[Y] / 2;
	start = (*game)->r[X] / 2;
	mid = (*game)->r[X] / 2;
	end = start + len / 2;
	start -= len / 2;
	black = ft_rgb(0, 0, 0);
	while (start < end)
	{
		if (start < mid - len / 10 || start > mid + len / 10)
			(*game)->img.data[start + (*game)->r[X] * (y + k)] = black;
		start++;
	}
}

void		draw_target(t_game **game)
{
	int len;
	int k;
	int red;
	int	mid[2];

	len = ((*game)->r[Y] / 30) > ((*game)->r[X] / 30) ?
	((*game)->r[Y] / 30) : ((*game)->r[X] / 30);
	k = -2;
	red = ft_rgb(255, 20, 20);
	mid[X] = (*game)->r[X] / 2;
	mid[Y] = (*game)->r[Y] / 2;
	while (++k < 2)
	{
		vertical_axis(game, len, k);
		horizontal_axis(game, len, k);
		(*game)->img.data[mid[X] + k + (*game)->r[X] * mid[Y]] = red;
		(*game)->img.data[mid[X] + (*game)->r[X] * (mid[Y] + k)] = red;
	}
}
