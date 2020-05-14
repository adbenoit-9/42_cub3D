#include "cub3d.h"

static int	find_dim(int *i, char *line)
{
	char	*nb;
	int		k;
	int		j;
	int		dim;

	k = 0;
	while(line[k + *i] >= '0' && line[k + *i] <= '9')
		k++;
	if (!(nb = malloc(sizeof(char) * (k + 1))))
		return (-1);
	j = 0;
	while(line[*i] >= '0' && line[*i] <= '9')
	{
		nb[j] = line[*i];
		(*i)++;
		j++;
	}
	nb[j] = 0;
	dim = ft_atoi(nb);
	free(nb);
	nb = NULL;
	return (dim);
}

void	add_dim_xpm(t_all **all, char *path, int *dimX, int *dimY)
{
	int		i;
	char	*line;
	char	*tmp;
	int		fd;

	i = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	while (i < 4)
	{
		free(line);
		line = NULL;
		if (get_next_line(fd, &line) != 1)
			ft_error(all, line, PATH_ERR);
		i++;
	}
	while (get_next_line(fd, &tmp) == 1)
		free(tmp);
	i = 1;
	if ((*dimX = find_dim(&i, line)) == -1)
		ft_error(all, line, FIND_ERR);
	i++;
	if ((*dimY = find_dim(&i, line)) == -1)
		ft_error(all, line, FIND_ERR);
	free(line);
	line = NULL;
	close(fd);
}

void    put_img(t_all **all, t_img *img, char *path)
{
	img->bpp = 32;
	img->endian = 0;
	add_dim_xpm(all, path, &img->dim[X], &img->dim[Y]);
	img->size_line = img->dim[X] * 4;
	if ((img->ptr = mlx_xpm_file_to_image((*all)->mlx, path, &img->dim[X], &img->dim[Y])) == NULL)
		ft_error(all, NULL, FILE_ERR);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
}