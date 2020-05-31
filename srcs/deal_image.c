/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:57:08 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/31 18:02:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_all **all, t_img *img, char *path)
{
	img->bpp = 32;
	img->endian = 0;
	img->dim[X] = 0;
	img->dim[Y] = 0;
	img->size_line = 0;
	if ((img->ptr = mlx_xpm_file_to_image((*all)->mlx_ptr,
			path, &img->dim[X], &img->dim[Y])) == NULL)
		exit_error(all, NULL, IMG_ERR);
	img->data = (int *)mlx_get_data_addr(img->ptr,
			&img->bpp, &img->size_line, &img->endian);
}

void	load_tab_of_image(t_all **all, t_tab_img *img, char **path, int start)
{
	int i;

	i = 0;
	img->bpp = 32;
	img->endian = 0;
	while (i < 4)
	{
		img->dim[i][X] = 0;
		img->dim[i][Y] = 0;
		img->size_line = 0;
		if ((img->ptr[i] = mlx_xpm_file_to_image((*all)->mlx_ptr,
				path[start + i], &img->dim[i][X], &img->dim[i][Y])) == NULL)
			exit_error(all, NULL, IMG_ERR);
		img->data[i] = (int *)mlx_get_data_addr(img->ptr[i],
				&img->bpp, &img->size_line, &img->endian);
		i++;
	}
}
