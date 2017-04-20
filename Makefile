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
NAME2 = checker
MAIN1 = push_swap.c
MAIN2 = checker.c
SRC = commands.c include.c middle.c sort.c dop.c
CC = gcc
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all re clean fclean

all: $(NAME1) $(NAME2)

$(NAME2): $(LIB) $(SRC:.c=.o) $(MAIN2:.c=.o)
	@echo ">\033[32mCompiling Checker program\033[0m"
	@ $(CC) -o $(NAME2) $(LIB) $(SRC:.c=.o) $(MAIN2:.c=.o) $(FLAGS)
	@echo ">\033[32mCompiling of Checker finished successfuly!\033[0m\n"

$(NAME1): $(LIB) $(SRC:.c=.o) $(MAIN1:.c=.o)
	@echo ">\033[32mCompiling executable file\033[0m"
	@ $(CC) -o $(NAME1) $(LIB) $(SRC:.c=.o) $(MAIN1:.c=.o) $(FLAGS)
	@echo ">\033[32mCompiling finished successfuly!\033[0m\n"

$(LIB):
	@echo ">\033[32mStarting compile LIBFT library...\033[0m"
	@make -C ./libft
	@echo ">\033[32mStarting compile project files...\033[0m"

$(MAIN1:.c=.o): $(MAIN1)
	@ $(CC) -o $@ -c $< $(FLAGS)

$(MAIN2:.c=.o): $(MAIN2)
	@ $(CC) -o $@ -c $< $(FLAGS)

%.o: %.c
	@ $(CC) -o $@ -c $< $(FLAGS)

clean:
	@make clean -C ./libft
	@rm -f $(SRC:.c=.o) $(MAIN1:.c=.o) $(MAIN2:.c=.o)

fclean: clean
	@rm -f $(LIB) $(NAME1) $(NAME2)
	@echo ">\033[32mCleaning successfull!\033[0m\n"

re: fclean all
