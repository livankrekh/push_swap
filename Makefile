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
	@echo ">\033[32mCompiling executable file\033[0m"
	@ $(CC) -o $(NAME1) $(LIB) $(SRC:.c=.o) $(FLAGS)
	@echo ">\033[32mCompiling finished successfuly!\033[0m\n"

$(LIB):
	@echo ">\033[32mStarting compile LIBFT library...\033[0m"
	@make -C ./libft
	@echo ">\033[32mStarting compile project files...\033[0m"

%.o: %.c
	@ $(CC) -o $@ -c $< $(FLAGS)

clean:
	@make clean -C ./libft
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(LIB) $(NAME1)
	@echo ">\033[32mCleaning successfull!\033[0m\n"

re: fclean all
