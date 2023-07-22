# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaengha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:53:50 by psaengha          #+#    #+#              #
#    Updated: 2023/07/23 01:56:09 by psaengha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	fdf.c \
		readfdf.c \
		createmap.c \
		createmap_utils.c
OBJ = $(SRC:%.c=%.o)
LIBFT = utils/libft/libft.a
GETNEXTLINE = utils/get_next_line/get_next_line.a
PRINTF = utils/ft_printf/libftprintf.a
MINILIB = minilibx_macos/libmlx.a

INCS_DIR = ./includes
IFLAGS = -I $(INCS_DIR)
LEAK = -fsanitize=address
GCC_FLAGS = gcc -Wall -Wextra -Werror -g -Iinclude $(LEAK)

all: $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJ)
	make -C ./utils/libft
	make -C ./utils/get_next_line
	make -C ./utils/ft_printf
	$(GCC_FLAGS) $^ $(LIBFT) $(GETNEXTLINE) $(PRINTF) $(MINILIB) -framework OpenGL -framework AppKit -o $@
# $(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C ./utils/libft
	make clean -C ./utils/get_next_line
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./utils/libft
	make fclean -C ./utils/get_next_line
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
