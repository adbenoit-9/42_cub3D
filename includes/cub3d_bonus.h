/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:58:52 by Adeline           #+#    #+#             */
/*   Updated: 2020/06/08 22:57:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"
# include "cub3d_macros_bonus.h"

void			draw_mini_map(t_game **game);
void			check_door(t_game **game);
void			draw_all_sprites(t_game **game, t_sprite *sp);
void			draw_door(t_game **game);
void			draw_hearts(t_game **game);
void			draw_replay(t_game **game, t_img *im, int k1, int k2);
void			draw_weapon(t_game **game, t_tab_img *weap);
void			manage_life(t_game **game, char c);
void			deal_door(t_game **game);
int				ft_mouse(int button, int x, int y, t_game **game);

#endif
