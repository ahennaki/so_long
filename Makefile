# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 15:12:34 by aennaki           #+#    #+#              #
#    Updated: 2023/07/02 11:54:50 by aennaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/movement.c src/errors.c src/placement.c src/map.c src/path.c src/so_long.c
OBJ_SRC = $(SRC:.c=.o)
UTL = util/get_next_line.c util/get_next_line_utils.c util/ft_strdup.c util/ft_printf.c \
		util/ft_printfmt.c util/printf_utils.c
OBJ_UTL = $(UTL:.c=.o)
LIB = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MLX = minilibx/

HEADERS = headers/*.h

all: $(NAME)
	
%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME) : $(OBJ_UTL) $(OBJ_SRC)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(LIB) $^ -o $(NAME)

clean:
		make clean -C $(MLX)
		rm -rf $(OBJ_UTL) $(OBJ_SRC)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
