# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 15:12:34 by aennaki           #+#    #+#              #
#    Updated: 2023/02/25 15:17:06 by aennaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/movement.c src/errors.c src/placement.c src/map.c src/path.c src/so_long.c
OBJ_SRC = $(SRC:.c=.o)
UTL = util/get_next_line.c util/get_next_line_utils.c util/ft_strdup.c util/ft_printf.c \
		util/ft_printfmt.c util/printf_utils.c
OBJ_UTL = $(UTL:.c=.o)
LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MLX = minilibx/
SRC_BNS = bonus/movement_bonus.c bonus/enm_bonus.c bonus/errors_bonus.c bonus/map_bonus.c \
			bonus/path_bonus.c bonus/placement_bonus.c bonus/so_long_bonus.c
OBJ_BNS = $(SRC_BNS:.c=.o)
HEADERS = headers/*.h

all: $(NAME)
	
%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME) : $(OBJ_UTL) $(OBJ_SRC)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(LIB) $^ -o $(NAME)
	
bonus : $(NAME_B)

$(NAME_B) : $(OBJ_UTL) $(OBJ_BNS)
	$(CC) $(CFLAGS) $(LIB) $^ -o $(NAME_B)

clean:
		make clean -C $(MLX)
		rm -rf $(OBJ_UTL) $(OBJ_SRC) $(OBJ_BNS)

fclean: clean
		rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY : all bonus clean fclean re
