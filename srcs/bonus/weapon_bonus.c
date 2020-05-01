#include "cub3d.h"

void    put_bonus_weapon(t_all **all)
{
	(*all)->bonus.weap.bpp = 32;
	(*all)->bonus.weap.endian = 0;
	add_dim_xpm(all, "./xpm/bow_pulling_0.xpm", &(*all)->bonus.weap.dim[0][X], &(*all)->bonus.weap.dim[0][Y]);
	(*all)->bonus.weap.size_line = (*all)->bonus.weap.dim[0][X] * 4;
	if (((*all)->bonus.weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pulling_0.xpm", &(*all)->bonus.weap.dim[0][X], &(*all)->bonus.weap.dim[0][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->bonus.weap.data[0] = (int *)mlx_get_data_addr((*all)->bonus.weap.ptr, &(*all)->bonus.weap.bpp, &(*all)->bonus.weap.size_line, &(*all)->bonus.weap.endian);

    add_dim_xpm(all, "./xpm/bow_pulling_1.xpm", &(*all)->bonus.weap.dim[1][X], &(*all)->bonus.weap.dim[1][Y]);
	(*all)->bonus.weap.size_line = (*all)->bonus.weap.dim[1][X] * 4;
	if (((*all)->bonus.weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pulling_1.xpm", &(*all)->bonus.weap.dim[1][X], &(*all)->bonus.weap.dim[1][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->bonus.weap.data[1] = (int *)mlx_get_data_addr((*all)->bonus.weap.ptr, &(*all)->bonus.weap.bpp, &(*all)->bonus.weap.size_line, &(*all)->bonus.weap.endian);

    add_dim_xpm(all, "./xpm/bow_pulling_2.xpm", &(*all)->bonus.weap.dim[2][X], &(*all)->bonus.weap.dim[2][Y]);
	(*all)->bonus.weap.size_line = (*all)->bonus.weap.dim[2][X] * 4;
	if (((*all)->bonus.weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pulling_2.xpm", &(*all)->bonus.weap.dim[2][X], &(*all)->bonus.weap.dim[2][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->bonus.weap.data[2] = (int *)mlx_get_data_addr((*all)->bonus.weap.ptr, &(*all)->bonus.weap.bpp, &(*all)->bonus.weap.size_line, &(*all)->bonus.weap.endian);

    add_dim_xpm(all, "./xpm/bow_pull_3.xpm", &(*all)->bonus.weap.dim[3][X], &(*all)->bonus.weap.dim[3][Y]);
	(*all)->bonus.weap.size_line = (*all)->bonus.weap.dim[3][X] * 4;
	if (((*all)->bonus.weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pull_3.xpm", &(*all)->bonus.weap.dim[3][X], &(*all)->bonus.weap.dim[3][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->bonus.weap.data[3] = (int *)mlx_get_data_addr((*all)->bonus.weap.ptr, &(*all)->bonus.weap.bpp, &(*all)->bonus.weap.size_line, &(*all)->bonus.weap.endian);
}

void    print_bonus_weapon(t_all **all, int pull)
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