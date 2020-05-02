/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:42:55 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/02 13:26:30 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void lose_win_life(t_all **all)
{
    int i;

    i = (*all)->sp.count - 1;
    if ((int)(*all)->player.map[X] == (*all)->sp.pos[i][X] && (int)(*all)->player.map[Y] == (*all)->sp.pos[i][Y])
        (*all)->bonus.life--;
}
void    put_heart(t_all **all)
{
	(*all)->bonus.heart.bpp = 32;
	(*all)->bonus.heart.endian = 0;
	add_dim_xpm(all, "./xpm/heart.xpm", &(*all)->bonus.heart.dim[X], &(*all)->bonus.heart.dim[Y]);
	(*all)->bonus.heart.size_line = (*all)->bonus.heart.dim[X] * 4;
	if (((*all)->bonus.heart.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/heart.xpm", &(*all)->bonus.heart.dim[X], &(*all)->bonus.heart.dim[Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->bonus.heart.data = (int *)mlx_get_data_addr((*all)->bonus.heart.ptr, &(*all)->bonus.heart.bpp, &(*all)->bonus.heart.size_line, &(*all)->bonus.heart.endian);
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
    start[X] = (*all)->r[X] - (w * 6 + w / 2 * 6);
    while (i <= (*all)->bonus.life)
    {
        //printf("i = %d\n", i);
        end[X] = start[X] + w;
        index[X] = 0;
        while (start[X] < end[X])
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
		    start[X]++;
        }
        i++;
        start[X] += w / 2;
    }
    
}