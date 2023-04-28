# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:13:26 by hel-hosr          #+#    #+#              #
#    Updated: 2023/04/25 11:13:29 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp
NAME = megaphone
CC = c++
FLAGS = -Wextra -Wall -Werror -std=c++98
AR = ar rcs
OBJ = $(SRCS:.cpp=.o)
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		$(REMOVE) $(OBJ)

fclean: clean
		$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re