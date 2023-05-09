# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:13:26 by hel-hosr          #+#    #+#              #
#    Updated: 2023/05/02 10:24:23 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
INC_DIR = includes/

SRCS = $(wildcard $(SRC_DIR)*.cpp)
INCS = $(wildcard $(INC_DIR)*.hpp)
NAME = sed
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
	$(REMOVE) $(wildcard *.replace)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
