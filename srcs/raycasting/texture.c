/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:34:57 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/05 18:31:31 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	//free(nb);
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
		//free(line);
		line = NULL;
		if (get_next_line(fd, &line) != 1)
			ft_error(all, line, PATH_ERR);
		i++;
	}
	while (get_next_line(fd, &tmp) == 1)
		free(tmp);
	i = 1;
	if ((*dimX = find_dim(&i, line)) == -1)
		ft_error(all, line, PATH_ERR);
	i++;
	if ((*dimY = find_dim(&i, line)) == -1)
		ft_error(all, line, PATH_ERR);
	//free(line);
	line = NULL;
	close(fd);
}

void	put_text(t_all **all)
{
	int i;

	i = 0;
	(*all)->text.bpp = 32;
	(*all)->text.endian = 0;
	while (i < 4)
	{
		(*all)->text.dim[i][X] = 0;
		(*all)->text.dim[i][Y] = 0;
		add_dim_xpm(all, (*all)->info[i], &(*all)->text.dim[i][X], &(*all)->text.dim[i][Y]);
		(*all)->text.size_line = (*all)->text.dim[i][X] * 4;
		if (((*all)->text.ptr = mlx_xpm_file_to_image((*all)->mlx, (*all)->info[i], &(*all)->text.dim[i][X], &(*all)->text.dim[i][Y])) == NULL)
			ft_error(all, NULL, PARS_ERR);
		(*all)->text.data[i] = (int *)mlx_get_data_addr((*all)->text.ptr, &(*all)->text.bpp, &(*all)->text.size_line, &(*all)->text.endian);
		i++;
	}
}

void	complete_text(t_all **all)
{
	(*all)->wall.dist[(*all)->grid.column] = wall_dist(all);
	if ((*all)->wall.side % 2 == 0)
		(*all)->wall.hit = (*all)->player.map[Y] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[Y];
	else
		(*all)->wall.hit = (*all)->player.map[X] + (*all)->wall.dist[(*all)->grid.column] * (*all)->wall.raydir[X];
	(*all)->wall.hit -= (int)(*all)->wall.hit;
	(*all)->text.pos[X] = (int)((*all)->wall.hit * (double)(*all)->text.dim[(*all)->wall.side][X]);
	if((*all)->wall.side == 0 && (*all)->wall.raydir[X] > 0)
		(*all)->text.pos[X] = (*all)->text.dim[(*all)->wall.side][X] - (*all)->text.pos[X] - 1;
	if((*all)->wall.side == 1 && (*all)->wall.raydir[Y] < 0)
		(*all)->text.pos[X] = (*all)->text.dim[(*all)->wall.side][X] - (*all)->text.pos[X] - 1;
}