# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2020/02/28 17:22:48 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= check_info.c ft_atoi.c ft_memcpy.c ft_realloc.c ft_strtrim.c ft_error.c ft_putnbr_fd.c ft_space.c get_next_line.c get_next_line_utils.c map.c parsing.c main.c start.c raycast.c

OBJS	= ${SRCS:.c=.o}

NAME	= cub3d.a

RM	= rm -f

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all:	${NAME}

.c.o:
	cc -fsanitize=address -I /minilibx_opengl_20191021/include ${SRCS} -lmlx -framework OpenGL -framework AppKit

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re
