# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:26:50 by emansoor          #+#    #+#              #
#    Updated: 2024/10/21 09:47:09 by emansoor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_printf.c\
		ft_printf_numbers.c\
		ft_printf_strings.c\
		ft_printf_puteverything.c

OFILES = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):
	make -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) -c $(CFILES)
	ar -rcs $(NAME) $(OFILES)

clean:
	make -C ./libft clean
	rm -f $(OFILES)

fclean: clean
	make -C ./libft fclean
	rm -f libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
