#include "cub3d.h"


static void	err_r(t_all **all, char *line, char *x, char *y)
{
	free(y);
	free(x);
	ft_error(all, line, PARS_ERR);
}

static int	pars_r(char *line, char **param, int i)
{
	int j;

	j = i;
	while (line[j] >= '0' && line[j] <= '9')
		j++;
	j -= i;
	if (!(*param = malloc(sizeof(char) * (j + 1))))
		return (-1);
	j = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		(*param)[j] = line[i];
		i++;
		j++;
	}
	(*param)[j] = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] < '0' && line[i] > '9')
		return (-1);
	return (i);
}

int			add_r(t_all **all, char *line)
{
	char	*x;
	char	*y;
	int		i;

	x = NULL;
	y = NULL;
	if ((*all)->r[X] != -1 || (*all)->r[Y] != -1)
		ft_error(all, line, PARS_ERR);
	i = 0;
	if ((i = pars_r(line, &x, i)) == -1)
		err_r(all, line, x, y);
	if ((i = pars_r(line, &y, i)) == -1)
		err_r(all, line, x, y);
	if (i != ft_strlen(line))
		err_r(all, line, x, y);
	if (((*all)->r[X] = ft_atoi(x)) > 2560)
		(*all)->r[X] = 2560;
	if (((*all)->r[Y] = ft_atoi(y)) > 1440)
		(*all)->r[Y] = 1440;
	if ((*all)->r[X] == -1 || (*all)->r[1] == -1)
		err_r(all, line, x, y);
	free(line);
	free(y);
	free(x);
	return (ft_parsing(all));	
}
