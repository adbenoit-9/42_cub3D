/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:33:01 by adbenoit          #+#    #+#             */
/*   Updated: 2020/03/12 20:01:57 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	t_all	*all;
	int		i;
	int		save;

	save = 0;
	if (ac != 2 && ac != 3)
		return (print_err(PARS_ERR));
	if(ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 6) == 0 || ft_strlen(av[2]) != 6)
			return (print_err(FILE_ERR));;
		save = 1;
	}
	i = 0;
	while (av[1][i] != '.')
		i++;
	if (ft_strncmp(av[1] + i, ".cub", 4) == 0)
		return (print_err(FILE_ERR));
	open_f(av[1], &all, save);
	i = 0;
	if (all->err < 0)
		all->err = map_end_error(&all);
	if (all->err >= 0)
		return (print_err(all->err));
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->r[X], all->r[Y], "Cub3D");
	start(&all);
	mlx_hook(all->win, 17, 1L << 0, ft_close, &all);
	//exit(EXIT_SUCCESS);
	//printf("win = %p\n", all->win);
	mlx_hook(all->win, KEY_PRESS, 1L << 0, ft_key_press, &all);
	mlx_hook(all->win, KEY_RELEASE, 1L << 1, ft_deal_key, &all);
	mlx_loop(all->mlx);
	//printf("loop = %d\n", mlx_loop(all->mlx));
	return (0);
}