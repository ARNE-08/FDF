# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaengha <psaengha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 09:35:19 by psaengha          #+#    #+#              #
#    Updated: 2022/11/05 14:06:06 by psaengha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c c.c s.c di.c u.c x.c xupper.c p.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean all re
