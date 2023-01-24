# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:13:26 by hel-hosr          #+#    #+#              #
#    Updated: 2023/01/20 11:18:47 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = ./src/
DIRLIBFT = ./libft/
DIRMLX = ./mlx/
NAME = so_long
LIBFTLIB = ./libft/libft.a
CC = cc -I /usr/local/include
FLAGS = -Wextra -Wall -Werror
AR = ar rcs
OBJ = $(SRCS:.c=.o)
REMOVE = rm -f

SRCS = $(addprefix $(SRCDIR),\
main.c\
struct_init_fill.c\
check_input.c\
check_input_2.c\
map_parse_1.c\
map_parse_2.c\
map_print.c\
game.c\
game_utils.c\
moves.c\
moves_collect.c\
error_exit.c)



all: $(NAME)

$(NAME):
		cd $(DIRLIBFT) && $(MAKE)
		cd $(DIRMLX) && $(MAKE)
		$(CC) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FLAGS) $(SRCS) $(LIBFTLIB)

clean:
		$(REMOVE) $(NAME)
		cd $(DIRLIBFT) && $(MAKE) clean
		cd $(DIRMLX) && $(MAKE) clean

fclean: clean
		$(REMOVE) $(NAME)
		cd $(DIRLIBFT) && $(MAKE) fclean
		cd $(DIRMLX) && $(MAKE) clean

re:	fclean all
	cd $(DIRLIBFT) && $(MAKE) fclean
	cd $(DIRLIBFT) && $(MAKE) all
	cd $(DIRMLX) && $(MAKE) clean
	cd $(DIRMLX) && $(MAKE) all

.PHONY: all clean fclean re
