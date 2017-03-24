# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 16:55:36 by liabanzh          #+#    #+#              #
#    Updated: 2017/03/20 16:55:38 by liabanzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
SRC = commands.c include.c middle.c push_swap.c sort.c dop.c
CC = gcc
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all re clean fclean

all: $(NAME1)

$(NAME1): $(LIB) $(SRC:.c=.o)
	$(CC) -o $(NAME1) $(LIB) $(SRC:.c=.o) $(FLAGS)

$(LIB):
	make -C ./libft

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	make clean -C ./libft
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(LIB) $(NAME1)

re: fclean all