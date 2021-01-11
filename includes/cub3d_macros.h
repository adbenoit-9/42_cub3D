/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:14:41 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/11 14:04:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MACROS_H
# define CUB3D_MACROS_H

# include "cub3d_macros_bonus.h"

# define INF_NO "NO "
# define INF_SO "SO "
# define INF_WE "WE "
# define INF_EA "EA "
# define INF_S "S "
# define INF_R "R "
# define INF_F "F "
# define INF_C "C "

# define NB_INFO 8
# define NB_BON 13

# define NO 1
# define SO 3
# define WE 0
# define EA 2
# define S 4
# define R 5
# define F 6
# define C 7

# define WALL '1'
# define OBJ '2'
# define EMPT '0'
# define HOLE ' '
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

# define NB_CHAR 8

# define X 0
# define Y 1

# define ROTSPEED 0.1
# define MOVESPEED 0.2

#endif
