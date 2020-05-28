/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:57:19 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/28 14:23:11 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_weapon(t_all **all, int pull)
{
	int		start[2];
	int		end[2];
    int     pix[2];
    int     index[2];
    int     h;
    int     w;

    h = abs((int)((*all)->r[Y] / 3));
    w = abs((int)((*all)->r[Y] / 2));
    start[X] = (*all)->r[X] / 2 - w / 2;
    end[X] = start[X] + w;
    index[X] = 0;
    while (start[X] < end[X])
	{
        index[Y] = 0;
        pix[X] = index[X] * (*all)->bonus.weap.dim[pull][X] / w;
		start[Y] = (*all)->r[Y] - h;
        end[Y] = start[Y] + h;
		while (start[Y] < end[Y])
		{
            pix[Y] = index[Y] * (*all)->bonus.weap.dim[pull][Y] / h;
		    if ((*all)->bonus.weap.data[pull][(int)((*all)->bonus.weap.dim[pull][X] * pix[Y] + pix[X])] != -16777216)
			    (*all)->img.data[start[X] + (*all)->r[X] * start[Y]] = (*all)->bonus.weap.data[pull][(int)((*all)->bonus.weap.dim[pull][X] * pix[Y] + pix[X])];
		    start[Y]++;
            index[Y]++;
		}
        index[X]++;
		start[X]++;
    }
}

void	ft_pull_weapon(t_all **all)
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
        print_play_again(all, &(*all)->bonus.win, 1, 1);
}