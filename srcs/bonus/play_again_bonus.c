#include "cub3d.h"

void    print_play_again(t_all **all)
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
        pix[X] = index[X] * (*all)->bonus.dead.dim[X] / w;
		start[Y] = (*all)->r[Y] / 2 - h / 2;
        end[Y] = start[Y] + h;
		while (start[Y] < end[Y])
		{
            pix[Y] = index[Y] * (*all)->bonus.dead.dim[Y] / h;
		    if ((*all)->bonus.dead.data[(int)((*all)->bonus.dead.dim[X] * pix[Y] + pix[X])] != -16777216)
			    (*all)->img.data[start[X] + (*all)->r[X] * start[Y]] = (*all)->bonus.dead.data[(int)((*all)->bonus.dead.dim[X] * pix[Y] + pix[X])];
		    start[Y]++;
            index[Y]++;
		}
        index[X]++;
		start[X]++;
    }
}

int     ft_mouse(int button, int x, int y, t_all **all)
{
    int start[2];
    int end[2];
    int i;

    start[X] = (*all)->r[X] / 2 - abs((int)((*all)->r[Y] / 2)) / 2;
    start[Y] = (*all)->r[Y] / 2 - abs((int)((*all)->r[Y] / 2)) / 2;
    end[X] = start[X] + abs((int)((*all)->r[Y] / 2));
    end[Y] = start[Y] + abs((int)((*all)->r[Y] / 2));
    if (button == 1 && (*all)->bonus.life == 0 && x > start[X] && x < end[X] && y > start[Y] && y < end[Y])
    {
        (*all)->bonus.col = 0;
        (*all)->player.map[X] = (*all)->player.pos[X];
		(*all)->player.map[Y] = (*all)->player.pos[Y];
        //ft_putdir(all, (*all)->player.o);
        create_image(all);
        (*all)->bonus.life = 5;
        i = 0;
	    while (i < (*all)->sp.count)
	    {
		    (*all)->sp.see[i] = 0;
		    (*all)->bonus.sa.see[i] = 0;
		    (*all)->sp.dead[i] = 0;
		    (*all)->bonus.sa.dead[i] = 1;
		    i++;
	    }
	    i = 0;
	    while (i < (*all)->bonus.sp.count)
	    {
		    (*all)->bonus.sp.see[i] = 0;
		    (*all)->bonus.sp.dead[i] = 0;
		    i++;
	    }
    }
    return (NO_ERR);
}