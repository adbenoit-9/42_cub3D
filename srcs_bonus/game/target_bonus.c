/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:34:08 by adbenoit          #+#    #+#             */
/*   Updated: 2020/08/04 18:26:35 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void     vertical_axis(t_game **game, int len, int k)
{
    int start;
    int x;
    int end;

    start = (*game)->r[Y] / 2;
    x = (*game)->r[X] / 2;
	end = start + len / 2;
    start -= len / 2;
	while (start < end)
	{
        if (start < (*game)->r[Y] / 2 - len / 10 || start > (*game)->r[Y] / 2 + len / 10)
            (*game)->img.data[x + k + (*game)->r[X] * start] = ft_rgb(0, 0, 0);
        start++;
	}
}

static void     horizontal_axis(t_game **game, int len, int k)
{
    int start;
    int y;
    int end;

    y = (*game)->r[Y] / 2;
    start = (*game)->r[X] / 2;
	end = start + len / 2;
    start -= len / 2;
	while (start < end)
	{
        if (start < (*game)->r[X] / 2 - len / 10 || start > (*game)->r[X] / 2 + len / 10)
            (*game)->img.data[start + (*game)->r[X] * (y + k)] = ft_rgb(0, 0, 0);
        start++;
	}
}

void            draw_target(t_game **game)
{
	int len;
    int k;
    int col;

    len = ((*game)->r[Y] / 30) > ((*game)->r[X] / 30) ?
        ((*game)->r[Y] / 30) : ((*game)->r[X] / 30);
    k = -2;
    col = ft_rgb(255, 20, 20);
    while (++k < 2)
    {
        vertical_axis(game, len, k);
        horizontal_axis(game, len, k);
        (*game)->img.data[(*game)->r[X] / 2 + k + (*game)->r[X] * (*game)->r[Y] / 2] = col;
        (*game)->img.data[(*game)->r[X] / 2 + (*game)->r[X] * ((*game)->r[Y] / 2 + k)] = col;
    }
}
