# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2020/08/07 14:41:52 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

INC			= includes/

HEADER		= $(INC)cub3d.h

H_BONUS		= $(INC)cub3d_bonus.h

# ************************************* PATHS ******************************** #

SRCS_PATH		=	srcs/
GAME_PATH		=	srcs/game/
PARS_PATH		=	srcs/parsing/
RAYC_PATH		=	srcs/raycasting/
BONUS_PATH		=	srcs_bonus/
GAME_PATH_BONUS	=	srcs_bonus/game/
PARS_PATH_BONUS	=	srcs_bonus/parsing/
RAYC_PATH_BONUS	=	srcs_bonus/raycasting/
UTILS_PATH		=	srcs_utils/

# ********************************** SRCS UTILS ****************************** #

UTILS	=	ft_atoi.c			ft_bzero.c\
			ft_free.c			ft_memcpy.c\
			ft_putnbr_fd.c		ft_realloc.c\
			ft_rgb.c			ft_strlen.c\
			ft_strncmp.c		ft_strtrim.c\
			get_next_line.c		get_next_line_utils.c

# ************************************* SRCS ********************************* #

SRCS	=	main.c

PARS	=	check_map.c		fill_data.c\
			parsing.c		parsing_util.c\
			handle_file.c

RAYC	=	sprite.c		sprite_utils.c\
			wall.c			wall_utils.c

GAME	=	bmp_file.c		clear.c\
			create_img.c	deal_image.c\
			exit_game.c		ft_deal_key.c\
			init_game.c		init_utils.c\
			mlx_handle.c	move.c\
			rotation.c		start_game.c

SRCS	+=	$(UTILS)
SRCS	+=	$(PARS)
SRCS	+=	$(RAYC)
SRCS	+=	$(GAME)

# ************************************ BONUS ********************************* #

BONUS		=	main_bonus.c

PARS_BONUS	+=	check_map_bonus.c		fill_data_bonus.c\
				parsing_bonus.c			parsing_util_bonus.c\
				handle_file_bonus.c\

RAYC_BONUS	+=	door_bonus.c			sprite_bonus.c\
				sprite_utils_bonus.c	wall_bonus.c\
				wall_utils_bonus.c

GAME_BONUS	+=	bmp_file_bonus.c		deal_door_bonus.c\
				exit_game_bonus.c		init_game_bonus.c\
				mini_map_bonus.c		replay_bonus.c\
				weapon_bonus.c			clear_bonus.c\
				deal_image_bonus.c		ft_deal_key_bonus.c\
				init_utils_bonus.c		mlx_handle_bonus.c\
				rotation_bonus.c		create_img_bonus.c\
				deal_sprite_bonus.c		heart_bonus.c\
				life_bonus.c			move_bonus.c\
				start_game_bonus.c		target_bonus.c

BONUS		+=	$(UTILS)
BONUS		+=	$(PARS_BONUS)
BONUS		+=	$(RAYC_BONUS)
BONUS		+=	$(GAME_BONUS)

# ********************************** UTILS ******************************* #

OBJ_PATH		=	obj/

OBJ_PATH_BONUS	=	obj_bonus/

OBJS_NAME		+=	$(SRCS:.c=.o)

OBJ_NAME_BONUS	+=	$(BONUS:.c=.o)

OBJS			=	$(addprefix $(OBJ_PATH),$(OBJS_NAME))

OBJ_BONUS		=	$(addprefix $(OBJ_PATH_BONUS),$(OBJ_NAME_BONUS))

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

MLX_DIR			=	minilibx

MLX				=	$(MLX_DIR)/libmlx.a

MLX_LIBS		=	-lmlx -lXext -lX11


# ************************************ RULES ******************************** #

all: $(MLX) $(NAME)

bonus: $(MLX) $(OBJ_BONUS)
	@printf "\n"
	@$(CC) -o $(NAME) $^ -framework OpenGL -framework AppKit
	@echo "Compilation of \033[33;1m$(NAME) bonus\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(MLX) :
	@make -C $(MLX_DIR) $(MLX_LIBS)
	@echo "Compilation of \033[33;1m$(MLX_DIR)\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(NAME): $(OBJS)
	@printf "\n"
	@$(CC) -o $(NAME) $(OBJS) $(MLX) -framework OpenGL -framework AppKit
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(OBJ_PATH)%.o:	$(SRCS_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(UTILS_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(PARS_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(RAYC_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH)%.o:	$(GAME_PATH)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

# ********************************* RULES BONUS ****************************** #


$(OBJ_PATH_BONUS)%.o:	$(BONUS_PATH)%.c $(H_BONUS)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_PATH_BONUS) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH_BONUS)%.o:	$(UTILS_PATH)%.c $(H_BONUS)
	@printf "\033[34;1m|\033[0;m"
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH_BONUS)%.o:	$(PARS_PATH_BONUS)%.c $(H_BONUS)
	@printf "\033[34;1m|\033[0;m"
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH_BONUS)%.o:	$(RAYC_PATH_BONUS)%.c $(H_BONUS)
	@printf "\033[34;1m|\033[0;m"
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_PATH_BONUS)%.o:	$(GAME_PATH_BONUS)%.c $(H_BONUS)
	@printf "\033[34;1m|\033[0;m"
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_PATH_BONUS)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

# ************************************ DEBUG ******************************** #

debug:
	@echo "\033[36;1m---------- \033[0;m\033[36;4mDEBUG\033[0;m\
	\033[36;1m ----------\033[0;m\n"
	@echo "\033[34;1mHEADER\033[0;m = $(HEADER)\n"
	@echo "\033[34;1mSRCS\033[0;m = $(SRCS)\n"
	@echo "\033[34;1mOBJS\033[0;m = $(OBJS)"
	@echo "\033[36;1m------------------------------ \033[0;m"

debug_bonus:
	@echo "\033[36;1m---------- \033[0;m\033[36;4mDEBUG BONUS\033[0;m\
	\033[36;1m ----------\033[0;m\n"
	@echo "\033[34;1mHEADER\033[0;m = $(H_BONUS)\n"
	@echo "\033[34;1mBONUS\033[0;m = $(BONUS)\n"
	@echo "\033[34;1mOBJS\033[0;m = $(OBJ_BONUS)"
	@echo "\033[36;1m------------------------------ \033[0;m"


.PHONY: all clean fclean re bonus debug debug_bonus