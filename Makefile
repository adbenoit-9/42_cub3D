# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Adeline <Adeline@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2020/05/28 21:22:07 by Adeline          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Cub3D

INC			= includes/

HEADER		= $(INC)cub3d.h

SRCS_PATH	= srcs

UTILS_PATH	= srcs/utils


OBL_PATH	= srcs/obligatory

RAY_PATH	= srcs/raycasting

BONUS_PATH	= srcs/bonus



SRCS_NAME	=	bmp_file.c\
				camera_move.c\
				check_map.c\
				clear.c\
				deal_image.c\
				exit_game.c\
				init_game.c\
				main.c\
				pars_color.c\
				pars_resolution.c\
				parsing.c\
				player_move.c

BONUS_NAME	=	all_sprite_bonus.c\
				create_img_bonus.c\
				door_bonus.c\
				ft_deal_key_bonus.c\
				heart_bonus.c\
				life_bonus.c\
				mlx_handle_bonus.c\
				mini_map_bonus.c\
				pars_bonus.c\
				pars_info_bonus.c\
				pars_map_bonus.c\
				raycast_door_bonus.c\
				replay_bonus.c\
				start_game_bonus.c\
				weapon_bonus.c

OBL_NAME	=	create_img.c\
				ft_deal_key.c\
				mlx_handle.c\
				pars_info.c\
				pars_map.c\
				start_game.c

RAY_NAME	=	sprite.c\
				sprite_utils.c\
				wall.c\
				wall_utils.c


UTILS_NAME	=	ft_atoi.c\
				ft_bzero.c\
				ft_free.c\
				ft_memcpy.c\
				ft_putnbr_fd.c\
				ft_realloc.c\
				ft_rgb.c\
				ft_strtrim.c\
				get_next_line.c\
				get_next_line_utils.c

OBJ_PATH	= obj

OBJ_B_PATH	= obj/bonus

OBJ_NAME	= $(UTILS_NAME:.c=.o)
OBJ_NAME	+= $(PARSO_NAME:.c=.o)
OBJ_NAME	+= $(SRCS_NAME:.c=.o)
OBJ_NAME	+= $(OBL_NAME:.c=.o)
OBJ_NAME	+= $(RAY_NAME:.c=.o)

OBJ_B_NAME	= $(UTILS_NAME:.c=.o)
OBJ_B_NAME	+= $(PARSB_NAME:.c=.o)
OBJ_B_NAME	+= $(SRCS_NAME:.c=.o)
OBJ_B_NAME	+= $(BONUS_NAME:.c=.o)
OBJ_B_NAME	+= $(RAY_NAME:.c=.o)

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

MLX_DIR	= minilibx

MLX	= $(MLX_DIR)/libmlx.a

MLX_LIBS	= -lmlx -lXext -lX11

SRC			= $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))
SRC			+= $(addprefix $(RAY_PATH)/,$(RAY_NAME))
SRC			+= $(addprefix $(UTILS_PATH)/,$(UTILS_NAME))
SRC			+= $(addprefix $(OBL_PATH)/,$(OBL_NAME))
SRC			+= $(addprefix $(PARSO_PATH)/,$(PARSO_NAME))

OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_B	= $(addprefix $(OBJ_B_PATH)/,$(OBJ_B_NAME))

all: $(MLX) $(NAME)

bonus: $(MLX) $(OBJ_B)
	@rm -rf $(NAME)
	@printf "\n"
	@$(CC) -o $(NAME) $(OBJ_B) $(MLX) -framework OpenGL -framework AppKit
	@echo "Compilation of \033[33;1m$(NAME) bonus\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(MLX) :
	@make -C $(MLX_DIR) $(MLX_LIBS)
	@echo "Compilation of \033[33;1m$(MLX_DIR)\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(NAME):	$(OBJ)
	@printf "\n"
	@$(CC) -o $(NAME) $(OBJ) $(MLX) -framework OpenGL -framework AppKit
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]"

######### OBLIGATOIRE #############

$(OBJ_PATH)/%.o:	$(UTILS_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)/%.o:	$(SRCS_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)/%.o:	$(RAY_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)/%.o:	$(OBL_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

######### BONUS #############

$(OBJ_B_PATH)/%.o:	$(UTILS_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_B_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_B_PATH)/%.o:	$(PARSB_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_B_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_B_PATH)/%.o:	$(SRCS_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_B_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_B_PATH)/%.o:	$(RAY_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_B_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_B_PATH)/%.o:	$(BONUS_PATH)/%.c $(HEADER)
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_B_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

debug:
	@echo SRC = $(SRC)
	@echo OBJ_B_NAME = $(OBJ_B_NAME)
	@echo "HEADER = $(HEADER)"

clean:
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_B_PATH)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re