#include "cub3d.h"

static int	check_hole(t_all **all, int i)
{
	int j;

	j = 0;
	while ((*all)->map[i][j])
	{
		if ((*all)->map[i][j] == HOLE)
		{
			if (j != 0 && (*all)->map[i][j - 1] != HOLE && (*all)->map[i][j - 1] != WALL)
				exit_error(all, NULL, MAP_ERR);
			if (j != ft_strlen((*all)->map[i]) - 1 && (*all)->map[i][j + 1] != HOLE && (*all)->map[i][j + 1] != WALL)
				exit_error(all, NULL, MAP_ERR);
			if (i != 0 && (*all)->map[i - 1][j] != HOLE && (*all)->map[i - 1][j] != WALL)
				exit_error(all, NULL, MAP_ERR);
			if (i != (*all)->map_index- 1 && (*all)->map[i + 1][j] != HOLE && (*all)->map[i + 1][j] != WALL)
				exit_error(all, NULL, MAP_ERR);
		}
		j++;
	}
	return (NO_ERR);
}

int			check_line_border(t_all **all)
{
	int j;

	j = 0;
	if ((*all)->state == END)
	{
		while ((*all)->map[(*all)->map_index- 1][j])
		{
			if ((*all)->map[(*all)->map_index- 1][j] != WALL && (*all)->map[(*all)->map_index- 1][j] != HOLE)
				exit_error(all, NULL, MAP_ERR);
			j++;
		}
		return (NO_ERR);
	}
	if (!((*all)->map = realloc_tab((*all)->map, (*all)->map_index+ 2)))
		exit_error(all, NULL, MAL_ERR);
	return (NO_ERR);
}

int			check_map_border(t_all **all)
{
	int i;
	int	j;
	int size1;
	int	size2;

	if ((*all)->player.start_pos != 1)
		exit_error(all, NULL, MAP_ERR);
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
				exit_error(all, NULL, MAP_ERR);
		}
		j = -2;
		if (size2 > size1 && i != (*all)->map_index- 1)
			j = size1 - 1;
		while (++j != -1 && (*all)->map[i][j])
		{
			if ((*all)->map[i][j] != WALL)
				exit_error(all, NULL, MAP_ERR);
		}
		check_hole(all, i);
	}
	return (NO_ERR);
}
