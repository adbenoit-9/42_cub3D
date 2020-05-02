/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:42:55 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/03 01:03:41 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void lose_win_life(t_all **all)
{
    int i;
    int x;
    int y;

    i = 0;
    x = (int)(*all)->player.map[X];
    y = (int)(*all)->player.map[Y];
    while (i < (*all)->sp.count)
    {
        if (x == (int)(*all)->sp.coor[i][X] && y == (int)(*all)->sp.coor[i][Y] && (*all)->sp.dead[i] == 0)
        {
            if (((*all)->bonus.loop2 > 25) && (*all)->bonus.life > 0)
            {
                (*all)->bonus.col = 100;
                (*all)->bonus.life--;
                (*all)->bonus.loop2 = 0;
            }
        }
        i++;
    }
    i = 0;
    while (i < (*all)->bonus.sp.count)
    {
        if (x == (int)(*all)->bonus.sp.coor[i][X] && y == (int)(*all)->bonus.sp.coor[i][Y] && (*all)->sp.dead[i] == 0)
        {
            if ((*all)->bonus.life < 5)
                (*all)->bonus.life++;
            (*all)->bonus.sp.dead[i] = 2;
            (*all)->bonus.col = 0;
        }
        i++;
    }
    if ((*all)->bonus.loop2 > 25)
        (*all)->bonus.loop2 = 0;
    if ((*all)->bonus.life == 0)
        print_play_again(all);
    (*all)->bonus.loop2++;
}

void    print_hearts(t_all **all)
{
	int		start[2];
	int		end[2];
    int     pix[2];
    int     index[2];
    int     h;
    int     w;
    int     i;

    i = 0;
    lose_win_life(all);
    h = abs((int)((*all)->r[Y] / 20));
    w = abs((int)((*all)->r[Y] / 20));
    start[X] = (*all)->r[X] - w / 2;
    while (i <= (*all)->bonus.life)
    {
        //printf("i = %d\n", i);
        end[X] = start[X] - w;
        index[X] = 0;
        while (start[X] > end[X])
	    {
            index[Y] = 0;
            pix[X] = index[X] * (*all)->bonus.heart.dim[X] / w;
		    start[Y] = h / 2;
            end[Y] = start[Y] + h;
		    while (start[Y] < end[Y])
		    {
                pix[Y] = index[Y] * (*all)->bonus.heart.dim[Y] / h;
		        if ((*all)->bonus.heart.data[(int)((*all)->bonus.heart.dim[X] * pix[Y] + pix[X])] != -16777216)
			        (*all)->img.data[start[X] + (*all)->r[X] * start[Y]] = (*all)->bonus.heart.data[(int)((*all)->bonus.heart.dim[X] * pix[Y] + pix[X])];
		        start[Y]++;
                index[Y]++;
		    }
            index[X]++;
		    start[X]--;
        }
        i++;
        start[X] -= w / 2;
    }
    
}