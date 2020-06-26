# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglorios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 13:33:12 by aglorios          #+#    #+#              #
#    Updated: 2020/03/11 14:39:59 by aglorios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
MLX = ./minilibx/libmlx.a
LIBFT = ./libft/libft.a
FOLDER = ./srcs
SRCS_LIST =	raycast_flat.c \
			raycast_draw.c \
			keyboard.c	\
			parsing.c	\
			parsing2.c	\
			check_errordata.c	\
			checkrscreen.c	\
			check_errormaps.c	\
			check_errormaps2.c	\
			check_pos.c	\
			checktexture.c	\
			checktexture2.c	\
			parsesprite.c	\
			sprites.c	\
			draw_sprites.c	\
			bmp.c	\
			utils.c	\
			conf.c	\
			newmap.c \
			main.c


SRC = $(addprefix ${FOLDER}/, ${SRCS_LIST})

FLGS = -Wall -Wextra -Werror

HEADER = ./include

FSAN = -g -fsanitize=address

all:
	make -C ./minilibx
	make -C ./libft
	gcc -g -o $(NAME) -I$(HEADER) $(FLGS) $(SRC) $(LIBFT) $(MLX) -lm -lX11 -lXext

clean: 
	make -C ./minilibx clean
	make -C ./libft clean
	rm -rf *.o

fclean:
	make -C ./minilibx clean
	make -C ./libft fclean
	rm -rf *.o
	rm -rf ${NAME}

re: fclean all

phony: all clean fclean re
