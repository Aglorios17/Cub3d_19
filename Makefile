# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglorios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 13:33:12 by aglorios          #+#    #+#              #
#    Updated: 2020/03/02 15:25:58 by aglorios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D
LIBFT_PATH 		= ./libft
MINILIBX_PATH   = ./minilibx
#SRCS_LIST 		= main.c
#SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})
SRCS 			= raycast_flat.c \
				  parsing.c	\
				  main.c

OBJS			= ${SRCS:.c=.o}
INCLUDE 		= cube3d.h
#FOLDER			= srcs
LIBFT 			= libft
MINILIBX 		= minilibx
CC				= gcc -g -Wall -Wextra -Werror #-fsanitize=address
RM				= rm -f
MLXFLAGS 		= -I ./minilibx -L ./minilibx -lmlx -framework OpenGl -framework Appkit
LIBFLAGS 		= -I ./libft -L ./libft -L . ./libft/*.c 
# -I Add the directory dir to the list of directories to be searched for header files
# -L Searches the library when linking

all:			libft_all minilibx_all ${NAME}
$(NAME):		${OBJS} 
				@$(CC) $(MLXFLAGS) $(LIBFLAGS) libft.a libmlx.a -I./ $(OBJS) -o $@ 
#				$(CC) -Lmlx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#%.o: %.c 		$(INCLUDE)
#				$(CC) $(CCFLAGS) -Imlx -Iinc -Ilibft -c -o $@ $<
#				$@gcc -Wall -Wextra -Werror -Imlx -Iinc -Ilibft -c $< -o $@
clean:			libft_clean minilibx_clean
				@${RM} ${OBJS}
fclean:			libft_fclean clean
				@${RM} ${NAME}
re:				fclean all

# In this last section we make other makefiles compile with the -C flag
# The -C flag makes you go to the appropriate path and do the asked command
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
