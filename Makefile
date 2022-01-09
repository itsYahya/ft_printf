# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 19:38:37 by yel-mrab          #+#    #+#              #
#    Updated: 2021/11/26 13:12:20 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
SRC = ft_checflags.c ft_checkspecifier.c ft_checkspecifier.c ft_printf.c ft_put_hexa.c ft_put_unsigned_numbers.c \
	ft_putnumbers.c ft_putstr.c ft_supplement.c ft_print_meme.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all 