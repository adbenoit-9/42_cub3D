#include "cub3d.h"

void    load_image(t_all **all, t_img *img, char *path)
{
	img->bpp = 32;
	img->endian = 0;
	img->dim[X] = 0;
	img->dim[Y] = 0;
	img->size_line = 0;
	if ((img->ptr = mlx_xpm_file_to_image((*all)->mlx_ptr, path, &img->dim[X], &img->dim[Y])) == NULL)
		exit_error(all, NULL, FILE_ERR);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
}

void	load_tab_of_image(t_all **all, t_tab_img *tab_img, char **path, int start)
{
	int i;

	i = 0;
	tab_img->bpp = 32;
	tab_img->endian = 0;
	while (i < 4)
	{
		tab_img->dim[i][X] = 0;
		tab_img->dim[i][Y] = 0;
		tab_img->size_line = 0;
		if ((tab_img->ptr[i] = mlx_xpm_file_to_image((*all)->mlx_ptr, path[start + i], &tab_img->dim[i][X], &tab_img->dim[i][Y])) == NULL)
			exit_error(all, NULL, IMG_ERR);
		tab_img->data[i] = (int *)mlx_get_data_addr(tab_img->ptr[i], &tab_img->bpp, &tab_img->size_line, &tab_img->endian);
		i++;
	}
}