# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:13:26 by hel-hosr          #+#    #+#              #
#    Updated: 2023/01/03 15:48:01 by hel-hosr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstnew.c\
	ft_lstsize.c\
	ft_char_str_functs.c\
	ft_dec_int_funct.c\
	ft_hex_functs.c\
	ft_isformat.c\
	ft_printf.c\
	ft_ptr_functs.c\
	ft_uint_functs.c\
	get_next_line.c
NAME = libft.a
CC = cc -c
FLAGS = -Wextra -Wall -Werror
AR = ar rc
OBJ = $(SRCS:.c=.o)
REMOVE = rm -f

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(HEADER) $(SRCS)
		$(AR) $(NAME) $(OBJ)

clean:
		$(REMOVE) $(OBJ)

fclean: clean
		$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
