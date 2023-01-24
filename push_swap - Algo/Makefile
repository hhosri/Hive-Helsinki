# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:13:26 by hel-hosr          #+#    #+#              #
#    Updated: 2023/01/09 12:11:09 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c\
	check_input.c\
	utils.c\
	fill_stack_a.c\
	utils_lst.c\
	op_swap.c\
	op_push.c\
	op_rotate.c\
	op_reverse_rotate.c\
	utils_sort_min.c\
	utils_sort_any.c\
	sort_small.c\
	clear_stack.c\
	sort_large.c\
	push_all_except_3.c\
	targets.c\
	cost.c\
	cheapest.c
DIRLIBFT = ./libft/
NAME = push_swap
LIBFTLIB = ./libft/libft.a
CC = cc -o
FLAGS = -Wextra -Wall -Werror
AR = ar rcs
OBJ = $(SRCS:.c=.o)
REMOVE = rm -f

all: $(NAME)

$(NAME):
		cd $(DIRLIBFT) && $(MAKE)
		$(CC) $(NAME) $(FLAGS) $(SRCS) $(LIBFTLIB)

clean:
		$(REMOVE) $(NAME)
		cd $(DIRLIBFT) && $(MAKE) clean

fclean: clean
		$(REMOVE) $(NAME)
		cd $(DIRLIBFT) && $(MAKE) fclean

re:	fclean all
	cd $(DIRLIBFT) && $(MAKE) fclean
	cd $(DIRLIBFT) && $(MAKE) all

.PHONY: all clean fclean re
