/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:33:01 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/12 14:31:11 by Adeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int ac, char **av)
{
	t_all	*all;
	int		i;
	int		save;

	save = 0;
	if (ac != 2 && ac != 3)
		print_err(ARG_ERR);
	if(ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 6) == 0 || ft_strlen(av[2]) != 6)
			print_err(ARG_ERR);
		save = 1;
	}
	i = 0;
	while (av[1][i] != '.' || (av[1][i + 1] && av[1][i + 1] == '.'))
		i++;
	if (ft_strncmp(av[1] + i, ".cub", 4) == 0 || ft_strlen(av[1] + i) != 4)
		print_err(FILE_ERR);
	open_f(av[1], &all, save);
	map_end_error(&all);
	mlx_handle(all);
	return (0);
}