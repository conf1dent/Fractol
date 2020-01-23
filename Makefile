# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 23:52:13 by bbekmama          #+#    #+#              #
#    Updated: 2020/01/23 11:06:32 by bbekmama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WWW = -Wall -Werror -Wextra
SRC = *.c
NAM = fractol
LIB = libft/libft.a
MLX = minilibx_macos/libmlx.a
FRM	= -framework OpenGL -framework Appkit libft/libft.a
OBJ = $(SRC:.c=.o)

all:
	make -C libft
	make -C minilibx_macos
	gcc $(WWW) $(SRC) -o $(NAM) $(MLX) $(FRM)
	echo "Compilation is successful"
clean:
	-rm -f $(OBJ)
	make -C libft/ clean
	make -C minilibx_macos/clean
fclean: clean
	/bin/rm -f $(NAM)
	make -C libft/fclean
re: fclean all