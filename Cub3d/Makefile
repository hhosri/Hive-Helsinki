# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:13:26 by hel-hosr          #+#    #+#              #
#    Updated: 2023/07/26 11:51:39 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR = includes/
SRC_DIR = src/

SRCS_TEMP = main.c\
	map_validation/file_validation.c\
	map_validation/errors.c\
	map_validation/map_settings_validation.c\
	map_validation/validation_utils.c\
	map_validation/utils.c\
	map_validation/fill_paths.c\
	map_validation/map_settings_validation_2.c\
	map_validation/exit_free.c\
	map_validation/map_validation.c\
	map_validation/map_validation_2.c\
	map_validation/map_validation_3.c\
	map_validation/map_validation_4.c\
	map_validation/map_validation_5.c\
	map_validation/get_sizes.c\
	map_validation/convert_colors.c\
	hooks/keyhooks.c\
	hooks/keyhook_utils.c\
	initialize.c \
	map_creation/init_image.c \
	map_creation/draw_player.c \
	map_creation/draw_map.c \
	map_creation/draw_map_utils.c \
	map_creation/draw_raycaster.c \
	map_creation/dda.c \
	map_creation/dda_utils.c \
	map_creation/assign_textures.c \
	map_creation/draw_texture.c \
	map_creation/check_position.c \
	map_creation/draw_texture_utils.c \
	
SRCS = $(addprefix $(SRC_DIR), $(SRCS_TEMP))


DIRLIBFT = ./src/libft/
NAME = cub3d
LIBFTLIB = ./src/libft/libft.a
CC = cc -I /usr/local/include
FLAGS = -Wextra -Wall -Werror
AR = ar rcs
OBJ = $(SRCS:.c=.o)
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTLIB)
		$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FLAGS) $(SRCS) $(LIBFTLIB)

$(OBJ): %.o: %.c
	cc -c $? -o $@

$(LIBFTLIB):
	cd $(DIRLIBFT) && $(MAKE)

clean:
		$(REMOVE) $(OBJ)
		cd $(DIRLIBFT) && $(MAKE) clean

fclean: clean
		$(REMOVE) $(NAME)
		cd $(DIRLIBFT) && $(MAKE) fclean

re:	fclean all
	cd $(DIRLIBFT) && $(MAKE) fclean
	cd $(DIRLIBFT) && $(MAKE) all

.PHONY: all clean fclean re
