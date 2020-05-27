#include "cub3d.h"

int			check_col(char *line, char *col, int i)
{
	int j;

	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		if (j == 3)
			return (-1);
		col[j] = line[i];
		i++;
		j++;
	}
	while (j < 4)
	{
		col[j] = 0;
		j++;
	}
	return (i);
}

static void	pars_col(t_all **all, char *line, int *col)
{
	char	red[4];
	char	green[4];
	char	blue[4];
	int		i;

	i = 0;
	if ((i = check_col(line, red, i)) == -1)
		exit_game(all, line, PARS_ERR);
	if (line[i] != ',')
		exit_game(all, line, PARS_ERR);
	i++;
	if ((i = check_col(line, green, i)) == -1)
		exit_game(all, line, PARS_ERR);
	if (line[i] != ',')
		exit_game(all, line, PARS_ERR);
	i++;
	if ((i = check_col(line, blue, i)) == -1 || i != ft_strlen(line))
		exit_game(all, line, PARS_ERR);
	col[0] = ft_atoi(red);
	col[1] = ft_atoi(green);
	col[2] = ft_atoi(blue);
}

int			add_col(t_all **all, char *line, int ident)
{
	int		col[3];
	int		i;

	pars_col(all, line, col);
	i = 0;
	while (i < 3)
	{
		if (col[i] < 0 || col[i] > 255)
			exit_game(all, line, PARS_ERR);
		i++;
	}
	if (ident == F)
	{
		if ((*all)->f != -1)
			exit_game(all, line, PARS_ERR);
		(*all)->f = ft_rgb(col[0], col[1], col[2]);
	}
	if (ident == C)
	{
		if ((*all)->c != -1)
			exit_game(all, line, PARS_ERR);
		(*all)->c = ft_rgb(col[0], col[1], col[2]);
	}
	free(line);
	return (ft_parsing(all));	
}