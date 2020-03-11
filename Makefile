# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2020/03/11 19:20:58 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRC_PATH	= .

SRC_NAME	= check_info.c ft_atoi.c ft_memcpy.c ft_realloc.c ft_strtrim.c ft_error.c ft_putnbr_fd.c ft_space.c get_next_line.c get_next_line_utils.c map.c parsing.c main.c start.c raycast.c move.c sprite.c texture.c bmp.c ft_bzero.c

OBJ_PATH	= obj

OBJ_NAME	= $(SRC_NAME:.c=.o)

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

MLX_DIR	= ressources/minilibx

MLX	= $(MLX_DIR)/libmlx.a

MLX_LIBS	= -lmlx -framework OpenGL -framework AppKit -lz

SRC	= $(addprefix $(SRC_PATH)/,$(SR_NAME))

OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME):	$(OBJ)
	@printf "\n"
	@$(CC) $^ -lmlx -framework OpenGL -framework AppKit -lz -o $@
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re