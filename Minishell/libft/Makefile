# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 12:00:04 by corellan          #+#    #+#              #
#    Updated: 2023/01/28 10:16:47 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_freesplit.c

OUT = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o \
ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o \
ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o \
ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o \
ft_lstlast.o ft_lstmap.o ft_lstnew.o ft_lstsize.o ft_freesplit.o

GNL_DIR = get_next_line

PF_DIR = ft_printf

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

PF_SRC = ft_printf/ft_print_address.c ft_printf/ft_print_hex.c \
ft_printf/ft_print_hex_u.c ft_printf/ft_printf.c ft_printf/ft_uitoa.c \
ft_printf/ft_writer.c

GNL_OUT = get_next_line.o get_next_line_utils.o

PF_OUT = ft_print_address.o ft_print_hex.o ft_print_hex_u.o ft_printf.o \
ft_uitoa.o ft_writer.o

FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OUT) $(GNL_OUT) $(PF_OUT)
		$(CC) $(FLAGS) -I. -c $(SRC)
		ar rc $(NAME) $(OUT) $(GNL_OUT) $(PF_OUT)

$(GNL_OUT):
		$(CC) $(FLAGS) -I$(GNL_DIR) -c $(GNL_SRC)

$(PF_OUT):
		$(CC) $(FLAGS) -I$(PF_DIR) -c $(PF_SRC)

clean:
		rm -f $(OUT) $(GNL_OUT) $(PF_OUT)

fclean: clean
		rm -f $(NAME)

re: fclean all