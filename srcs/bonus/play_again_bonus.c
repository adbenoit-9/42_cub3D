#include "cub3d.h"

void    print_play_again(t_all **all, t_img *im, int k1, int k2)
{
    int		start[2];
	int		end[2];
    int     pix[2];
    int     index[2];
    int     h;
    int     w;

    h = abs((int)((*all)->r[Y] / k1));
    w = abs((int)((*all)->r[X] / k2));
    start[X] = (*all)->r[X] / 2 - w / 2;
    end[X] = start[X] + w;
    index[X] = 0;
    while (start[X] < end[X])
	{
        index[Y] = 0;
        pix[X] = index[X] * im->dim[X] / w;
		start[Y] = (*all)->r[Y] / 2 - h / 2;
        end[Y] = start[Y] + h;
		while (start[Y] < end[Y])
		{
            pix[Y] = index[Y] * im->dim[Y] / h;
		    if (im->data[(int)(im->dim[X] * pix[Y] + pix[X])] != -16777216)
			    (*all)->img.data[start[X] + (*all)->r[X] * start[Y]] = im->data[(int)(im->dim[X] * pix[Y] + pix[X])];
		    start[Y]++;
            index[Y]++;
		}
        index[X]++;
		start[X]++;
    }
}

static void reinit_map(t_all **all)
{
    int i;
    int j;

    i = 0;
    while ((*all)->map[i])
    {
        j = 0;
        while ((*all)->map[i][j])
        {
            if ((*all)->map[i][j] == OPEN)
                (*all)->map[i][j] = DOOR;
            if ((*all)->map[i][j] == WALL_DOOR)
                (*all)->map[i][j] = WALL;
            if ((*all)->map[i][j] == DEAD)
            {
                (*all)->bonus.foe++;
                (*all)->map[i][j] = OBJ1;
            }
            if ((*all)->map[i][j] == (*all)->player.start_o)
            {
                (*all)->player.map[X] = j + 0.5;
			    (*all)->player.map[Y] = i + 0.5;
            }
            j++;
        }
        i++;
    }
}

int     ft_mouse(int button, int x, int y, t_all **all)
{
    int start[2];
    int end[2];
    int i;

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
    if (button == TRUE && ((*all)->bonus.life == 0 || (*all)->bonus.foe == 0) && x > start[X] && x < end[X] && y > start[Y] && y < end[Y])
    {
        reinit_map(all);
        ft_putdir(all, (*all)->player.start_o);
        (*all)->screen.plane[X] = ((*all)->player.dir[X] == 0) ? 0.66 : 0;
	    (*all)->screen.plane[Y] = ((*all)->player.dir[Y] == 0) ? 0.66 : 0;
        (*all)->bonus.col = 0;
        (*all)->bonus.life = 5;
	    i = 0;
	    while (i < (*all)->sp.count)
	    {
		    (*all)->sp.see[i] = 0;
		    (*all)->sp.dead[i] = 0;
		    i++;
	    }
    }
    return (NO_ERR);
}