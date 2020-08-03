/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:58:52 by Adeline           #+#    #+#             */
/*   Updated: 2020/08/03 14:50:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d_macros_bonus.h"
# include "cub3d.h"

void			clear_image(t_game **game);
void			deal_door(t_game **game);
void			draw_door(t_game **game);
void			draw_hearts(t_game **game);
void			draw_mini_map(t_game **game);
void			draw_replay(t_game **game, t_img *im, int k1, int k2);
void			draw_weapon(t_game **game, t_tab_img *weap);
void			manage_life(t_game **game, char c);
int				ft_mouse(int button, int x, int y, t_game **game);
int				parse_bonus(char *line, t_game **game);

#endif
