# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 17:50:45 by hel-hosr          #+#    #+#              #
#    Updated: 2023/05/08 16:25:33 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
INC_DIR = includes/

SRCS = $(wildcard $(SRC_DIR)*.cpp)
INCS = $(wildcard $(INC_DIR)*.hpp)
NAME = scavtrap
CC = c++
FLAGS = -Wextra -Wall -Werror -std=c++98
AR = ar rcs
OBJ = $(SRCS:.cpp=.o)
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I$(INC_DIR) $(OBJ) -o $(NAME)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
