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

NAME 			= cub3D
LIBFT_PATH 		= ./libft
MINILIBX_PATH   = ./minilibx
SRCS_LIST		= raycast_flat.c \
				raycast_draw.c \
				keyboard.c	\
				parsing.c	\
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
				main.c

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})
OBJS			= ${SRCS:.c=.o}
INCLUDE 		= cube3d.h
FOLDER			= srcs
LIBFT 			= libft
MINILIBX 		= minilibx
CC				= gcc -g -Wall -Wextra -Werror #-fsanitize=address
RM				= rm -f
MLXFLAGS 		= -I ./minilibx -L ./minilibx -lmlx -framework OpenGl -framework Appkit
LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c 

all:			libft_all minilibx_all ${NAME}
$(NAME):		${OBJS} 
				@$(CC) $(MLXFLAGS) $(LIBFLAGS) libft.a libmlx.a -I./ $(OBJS) -o $@ 
clean:			libft_clean minilibx_clean
				@${RM} ${OBJS}
fclean:			libft_fclean clean
				@${RM} ${NAME}
re:				fclean all

libft_all:
	make -C $(LIBFT_PATH) all
	cp ./libft/libft.a libft.a

libft_clean:
	make -C $(LIBFT_PATH) clean

libft_fclean:
	make -C $(LIBFT_PATH) fclean
	$(RM) libft.a

minilibx_all:
	make -C $(MINILIBX_PATH) all
	cp ./minilibX/libmlx.a libmlx.a

minilibx_clean:
	make -C $(MINILIBX_PATH) clean
	$(RM) libmlx.a
				
.PHONY: all fclean clean re
