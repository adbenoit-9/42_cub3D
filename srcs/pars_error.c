#include "cub3d.h"

int			map_error(t_all **all)
{
	int j;

	j = 0;
	if ((*all)->state == END)
	{
		while ((*all)->map[(*all)->i_map - 1][j])
		{
			if ((*all)->map[(*all)->i_map - 1][j] != WALL && (*all)->map[(*all)->i_map - 1][j] != HOLE)
				exit_game(all, NULL, PARS_ERR);
			j++;
		}
		return (NO_ERR);
	}
	if (!((*all)->map = realloc_tab((*all)->map, (*all)->i_map + 2)))
		exit_game(all, NULL, MAL_ERR);
	return (NO_ERR);
}

static int	verif_hole(t_all **all, int i)
{
	int j;

	j = 0;
	while ((*all)->map[i][j])
	{
		if ((*all)->map[i][j] == HOLE)
		{
			if (j != 0 && (*all)->map[i][j - 1] != HOLE && (*all)->map[i][j - 1] != WALL)
				exit_game(all, NULL, PARS_ERR);
			if (j != ft_strlen((*all)->map[i]) - 1 && (*all)->map[i][j + 1] != HOLE && (*all)->map[i][j + 1] != WALL)
				exit_game(all, NULL, PARS_ERR);
			if (i != 0 && (*all)->map[i - 1][j] != HOLE && (*all)->map[i - 1][j] != WALL)
				exit_game(all, NULL, PARS_ERR);
			if (i != (*all)->i_map - 1 && (*all)->map[i + 1][j] != HOLE && (*all)->map[i + 1][j] != WALL)
				exit_game(all, NULL, PARS_ERR);
		}
		j++;
	}
	return (NO_ERR);
}

int			map_end_error(t_all **all)
{
	int i;
	int	j;
	int size1;
	int	size2;

	if ((*all)->pos != 1)
		exit_game(all, NULL, PARS_ERR);
	i = -1;
	size1 = 0;
	size2 = 0;
	while ((*all)->map[++i])
	{
		j = -2;
		size2 = ft_strlen((*all)->map[i]);
		if (i != 0)
			size1 = ft_strlen((*all)->map[i - 1]);
		if (i == 0)
			size1 = ft_strlen((*all)->map[i + 1]);
		if (size1 > size2 && i != 0)
			j = size2 - 1;
		while (++j != -1 && (*all)->map[i - 1][j])
		{
			if ((*all)->map[i - 1][j] != WALL)
				exit_game(all, NULL, PARS_ERR);
		}
		j = -2;
		if (size2 > size1 && i != (*all)->i_map - 1)
			j = size1 - 1;
		while (++j != -1 && (*all)->map[i][j])
		{
			if ((*all)->map[i][j] != WALL)
				exit_game(all, NULL, PARS_ERR);
		}
		verif_hole(all, i);
	}
	return (NO_ERR);
}
