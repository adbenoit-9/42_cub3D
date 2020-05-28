
# include "cub3d.h"

void static   draw_heart_pixel(t_all **all, t_draw draw)
{
    draw.end[X] = draw.start[X] - draw.w;
    draw.index[X] = 0;
    while (draw.start[X] > draw.end[X])
	{
        draw.index[Y] = 0;
        draw.pix[X] = draw.index[X] * (*all)->bonus.heart.dim[X] / draw.w;
		draw.start[Y] = draw.h / 2;
        draw.end[Y] = draw.start[Y] + draw.h;
		while (draw.start[Y] < draw.end[Y])
		{
            draw.pix[Y] = draw.index[Y] * (*all)->bonus.heart.dim[Y] / draw.h;
		    if ((*all)->bonus.heart.data[(int)((*all)->bonus.heart.dim[X] * draw.pix[Y] + draw.pix[X])] != -16777216)
			    (*all)->img.data[draw.start[X] + (*all)->r[X] * draw.start[Y]] = (*all)->bonus.heart.data[(int)((*all)->bonus.heart.dim[X] * draw.pix[Y] + draw.pix[X])];
		    draw.start[Y]++;
            draw.index[Y]++;
		}
        draw.index[X]++;
		draw.start[X]--;
    }
    draw.start[X] -= draw.w / 2;
}

void    draw_hearts(t_all **all)
{
	t_draw  draw;
    int     i;

    manage_life(all, (*all)->bonus.map_c);
    draw.h = abs((int)((*all)->r[Y] / 20));
    draw.w = abs((int)((*all)->r[Y] / 20));
    draw.start[X] = (*all)->r[X] - draw.w / 2;
    i = 0;
    while (i <= (*all)->bonus.life)
    {
        draw_heart_pixel(all, draw);
        i++;
    }   
}
