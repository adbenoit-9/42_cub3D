#include "cub3d.h"

static int     max_len(t_all **all)
{
    int i;
    int max;

    max = 0;
    i = 0;
    while ((*all)->map[i])
    {
        if (ft_strlen((*all)->map[i]) > max)
            max = ft_strlen((*all)->map[i]);
        i++;
    }
    return (max);
}

static void     draw_square(t_all **all, int *j, int *i, int dim, int x, int y)
{
    int k;
    int col;

    k = 0;
    while (k < dim)
    {
        if ((*all)->map[x][y]== WALL || (*all)->map[x][y]== DOOR)
        {
            col = (*all)->img.data[*j + (*all)->r[X] * *i];
            (*all)->img.data[*i + (*all)->r[X] * *j] = ft_rgb(151, 153, 131);
        }
        if (y == (int)(*all)->player.map[X] && x == (int)(*all)->player.map[Y])
            (*all)->img.data[*i + (*all)->r[X] * *j] = ft_rgb(33, 81, 116);
        if ((*all)->map[x][y]== OBJ1)
            (*all)->img.data[*i + (*all)->r[X] * *j] = ft_rgb(213, 84, 84);
        k++;
        (*i)++;
    }
}

void    draw_mini_map(t_all **all)
{
    int start[2];
    int k;
    int dim;
    int i;
    int j;

    start[Y] = 0;
    i = ((*all)->r[Y] / (*all)->map_index) / 6;
    j = ((*all)->r[X] / max_len(all)) / 6;
    dim = i > j ? j : i;
    i = 0;
    while ((*all)->map[i])
    {
        k = 0;
        while (k < dim)
        {
            j = 0;
            start[X] = 0;
            while ((*all)->map[i][j])
            {
               draw_square(all, &start[Y], &start[X], dim, i, j);
               j++;
            }
            start[Y]++;
            k++;
        }
        i++;
    }
}