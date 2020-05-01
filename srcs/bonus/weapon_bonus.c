#include "cub3d.h"

void    put_weapon(t_all **all)
{
	(*all)->weap.bpp = 32;
	(*all)->weap.endian = 0;
	add_dim_xpm(all, "./xpm/bow_pulling_0.xpm", &(*all)->weap.dim[0][X], &(*all)->weap.dim[0][Y]);
	(*all)->weap.size_line = (*all)->weap.dim[0][X] * 4;
	if (((*all)->weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pulling_0.xpm", &(*all)->weap.dim[0][X], &(*all)->weap.dim[0][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->weap.data[0] = (int *)mlx_get_data_addr((*all)->weap.ptr, &(*all)->weap.bpp, &(*all)->weap.size_line, &(*all)->weap.endian);

    add_dim_xpm(all, "./xpm/bow_pulling_1.xpm", &(*all)->weap.dim[1][X], &(*all)->weap.dim[1][Y]);
	(*all)->weap.size_line = (*all)->weap.dim[1][X] * 4;
	if (((*all)->weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pulling_1.xpm", &(*all)->weap.dim[1][X], &(*all)->weap.dim[1][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->weap.data[1] = (int *)mlx_get_data_addr((*all)->weap.ptr, &(*all)->weap.bpp, &(*all)->weap.size_line, &(*all)->weap.endian);

    add_dim_xpm(all, "./xpm/bow_pulling_2.xpm", &(*all)->weap.dim[2][X], &(*all)->weap.dim[2][Y]);
	(*all)->weap.size_line = (*all)->weap.dim[2][X] * 4;
	if (((*all)->weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pulling_2.xpm", &(*all)->weap.dim[2][X], &(*all)->weap.dim[2][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->weap.data[2] = (int *)mlx_get_data_addr((*all)->weap.ptr, &(*all)->weap.bpp, &(*all)->weap.size_line, &(*all)->weap.endian);

    add_dim_xpm(all, "./xpm/bow_pull_3.xpm", &(*all)->weap.dim[3][X], &(*all)->weap.dim[3][Y]);
	(*all)->weap.size_line = (*all)->weap.dim[3][X] * 4;
	if (((*all)->weap.ptr = mlx_xpm_file_to_image((*all)->mlx, "./xpm/bow_pull_3.xpm", &(*all)->weap.dim[3][X], &(*all)->weap.dim[3][Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	(*all)->weap.data[3] = (int *)mlx_get_data_addr((*all)->weap.ptr, &(*all)->weap.bpp, &(*all)->weap.size_line, &(*all)->weap.endian);
}

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
        pix[X] = index[X] * (*all)->weap.dim[pull][X] / w;
		start[Y] = (*all)->r[Y] - h;
        end[Y] = start[Y] + h;
		while (start[Y] < end[Y])
		{
            pix[Y] = index[Y] * (*all)->weap.dim[pull][Y] / h;
		    if ((*all)->weap.data[pull][(int)((*all)->weap.dim[pull][X] * pix[Y] + pix[X])] != -16777216)
			    (*all)->img.data[start[X] + (*all)->r[X] * start[Y]] = (*all)->weap.data[pull][(int)((*all)->weap.dim[pull][X] * pix[Y] + pix[X])];
		    start[Y]++;
            index[Y]++;
		}
        index[X]++;
		start[X]++;
    }
}