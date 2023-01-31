# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:13:26 by hel-hosr          #+#    #+#              #
#    Updated: 2023/01/31 13:57:10 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SRVR = ./src/server.c
SRCS_CLNT = ./src/client.c

DIRLIBFT = ./libft/
SRVR_NAME = server
CLNT_NAME = client
LIBFTLIB = ./libft/libft.a
INC = -I ./inc/
CC = cc -o
FLAGS = -Wextra -Wall -Werror
AR = ar rcs
OBJ = $(SRCS:.c=.o)
REMOVE = rm -f

all: $(SRVR_NAME) $(CLNT_NAME)

$(SRVR_NAME):
		cd $(DIRLIBFT) && $(MAKE)
		$(CC) $(SRVR_NAME) $(INC) $(FLAGS) $(SRCS_SRVR) $(LIBFTLIB)

$(CLNT_NAME):
		$(CC) $(CLNT_NAME) $(INC) $(FLAGS) $(SRCS_CLNT) $(LIBFTLIB)

clean:
		$(REMOVE) $(CLNT_NAME)
		$(REMOVE) $(SRVR_NAME)
		cd $(DIRLIBFT) && $(MAKE) clean

fclean: clean
		$(REMOVE) $(CLNT_NAME)
		$(REMOVE) $(SRVR_NAME)
		cd $(DIRLIBFT) && $(MAKE) fclean

re:	fclean all
	cd $(DIRLIBFT) && $(MAKE) fclean
	cd $(DIRLIBFT) && $(MAKE) all

.PHONY: all clean fclean re
