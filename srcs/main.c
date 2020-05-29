/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:29:50 by adbenoit          #+#    #+#             */
/*   Updated: 2020/05/29 16:30:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all;
	int		i;
	int		save;

	save = 0;
	if (ac != 2 && ac != 3)
		print_error(ARG_ERR);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 6) == FALSE || ft_strlen(av[2]) != 6)
			print_error(ARG_ERR);
		save = 1;
	}
	i = 0;
	while (av[1][i] != '.' || (av[1][i + 1] && av[1][i + 1] == '.'))
		i++;
	if (ft_strncmp(av[1] + i, ".cub", 4) == FALSE || ft_strlen(av[1] + i) != 4)
		print_error(FILE_ERR);
	open_f(av[1], &all, save);
	check_map_border(&all);
	start_game(&all);
	mlx_handle(all);
	return (0);
}
