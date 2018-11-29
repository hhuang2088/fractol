# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/30 17:23:01 by hehuang           #+#    #+#              #
#    Updated: 2017/05/25 05:01:21 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = gcc

CFLAG = -g -c -Wall -Werror -Wextra

COMPILE = $(CC) $(CFLAG)

SRC_NAME = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_iswhitespace.c \
			ft_skipwhitespace.c \
			ft_strupper.c \
			ft_strlower.c \
			ft_intiter.c \
			btree_create_node.c \
			btree_apply_prefix.c \
			btree_apply_infix.c \
			btree_apply_suffix.c \
			ft_findchar.c \
			ft_realloc.c \
			get_next_line.c \
			ft_itoa_base.c \
			ft_utoa_base.c \
			ft_atoi_base.c \
			list_free.c \
			get_list_size.c \
			copy_list.c

OBJ_NAME = $(SRC_NAME:.c=.o)

AR = ar rc

RLIB = ranlib

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

ft_memset.o: ft_memset.c $(HEADER)
	$(CC) $(CFLAG) ft_memset.c

ft_bzero.o: ft_bzero.c $(HEADER)
	$(CC) $(CFLAG) ft_bzero.c

ft_memcpy.o: ft_memcpy.c $(HEADER)
	$(COMPILE) ft_memcpy.c

ft_memccpy.o: ft_memccpy.c $(HEADER)
	$(COMPILE) ft_memccpy.c

ft_memmove.o: ft_memmove.c $(HEADER)
	$(COMPILE) ft_memmove.c

ft_memchr.o: ft_memchr.c $(HEADER)
	$(COMPILE) ft_memchr.c

ft_memcmp.o: ft_memcmp.c $(HEADER)
	$(COMPILE) ft_memcmp.c

ft_strlen.o: ft_strlen.c $(HEADER)
	$(COMPILE) ft_strlen.c

ft_strdup.o: ft_strdup.c $(HEADER)
	$(COMPILE) ft_strdup.c

ft_strcpy.o: ft_strcpy.c $(HEADER)
	$(COMPILE) ft_strcpy.c

ft_strncpy.o: ft_strncpy.c $(HEADER)
	$(COMPILE) ft_strncpy.c

ft_strcat.o: ft_strcat.c $(HEADER)
	$(COMPILE) ft_strcat.c

ft_strncat.o: ft_strncat.c $(HEADER)
	$(COMPILE) ft_strncat.c

ft_strlcat.o: ft_strlcat.c $(HEADER)
	$(COMPILE) ft_strlcat.c

ft_strchr.o: ft_strchr.c $(HEADER)
	$(COMPILE) ft_strchr.c

ft_strrchr.o: ft_strrchr.c $(HEADER)
	$(COMPILE) ft_strrchr.c

ft_strstr.o: ft_strstr.c $(HEADER)
	$(COMPILE) ft_strstr.c

ft_strnstr.o: ft_strnstr.c $(HEADER)
	$(COMPILE) ft_strnstr.c

ft_strcmp.o: ft_strcmp.c $(HEADER)
	$(COMPILE) ft_strcmp.c

ft_strncmp.o: ft_strncmp.c $(HEADER)
	$(COMPILE) ft_strncmp.c

ft_atoi.o: ft_atoi.c $(HEADER)
	$(COMPILE) ft_atoi.c

ft_isalpha.o: ft_isalpha.c $(HEADER)
	$(COMPILE) ft_isalpha.c

ft_isdigit.o: ft_isdigit.c $(HEADER)
	$(COMPILE) ft_isdigit.c

ft_isalnum.o: ft_isalnum.c $(HEADER)
	$(COMPILE) ft_isalnum.c

ft_isascii.o: ft_isascii.c $(HEADER)
	$(COMPILE) ft_isascii.c

ft_isprint.o: ft_isprint.c $(HEADER)
	$(COMPILE) ft_isprint.c

ft_toupper.o: ft_toupper.c $(HEADER)
	$(COMPILE) ft_toupper.c

ft_tolower.o: ft_tolower.c $(HEADER)
	$(COMPILE) ft_tolower.c

ft_memalloc.o: ft_memalloc.c $(HEADER)
	$(COMPILE) ft_memalloc.c

ft_memdel.o: ft_memdel.c $(HEADER)
	$(COMPILE) ft_memdel.c

ft_strnew.o: ft_strnew.c $(HEADER)
	$(COMPILE) ft_strnew.c

ft_strdel.o: ft_strdel.c $(HEADER)
	$(COMPILE) ft_strdel.c

ft_strclr.o: ft_strclr.c $(HEADER)
	$(COMPILE) ft_strclr.c

ft_striter.o: ft_striter.c $(HEADER)
	$(COMPILE) ft_striter.c

ft_striteri.o: ft_striteri.c $(HEADER)
	$(COMPILE) ft_striteri.c

ft_strmap.o: ft_strmap.c $(HEADER)
	$(COMPILE) ft_strmap.c

ft_strmapi.o: ft_strmapi.c $(HEADER)
	$(COMPILE) ft_strmapi.c

ft_strequ.o: ft_strequ.c $(HEADER)
	$(COMPILE) ft_strequ.c

ft_strnequ.o: ft_strnequ.c $(HEADER)
	$(COMPILE) ft_strnequ.c

ft_strsub.o: ft_strsub.c $(HEADER)
	$(COMPILE) ft_strsub.c

ft_strjoin.o: ft_strjoin.c $(HEADER)
	$(COMPILE) ft_strjoin.c

ft_strtrim.o: ft_strtrim.c $(HEADER)
	$(COMPILE) ft_strtrim.c

ft_itoa.o: ft_itoa.c $(HEADER)
	$(COMPILE) ft_itoa.c

ft_putchar.o: ft_putchar.c $(HEADER)
	$(COMPILE) ft_putchar.c

ft_putstr.o: ft_putstr.c $(HEADER)
	$(COMPILE) ft_putstr.c

ft_putendl.o: ft_putendl.c $(HEADER)
	$(COMPILE) ft_putendl.c

ft_putnbr.o: ft_putnbr.c $(HEADER)
	$(COMPILE) ft_putnbr.c

ft_putchar_fd.o: ft_putnbr_fd.c $(HEADER)
	$(COMPILE) ft_putchar_fd.c

ft_putstr_fd.o: ft_putstr_fd.c $(HEADER)
	$(COMPILE) ft_putstr_fd.c

ft_putendl_fd.o: ft_putendl_fd.c $(HEADER)
	$(COMPILE) ft_putendl_fd.c

ft_putnbr_fd.o: ft_putnbr_fd.c $(HEADER)
	$(COMPILE) ft_putnbr_fd.c

ft_lstnew.o: ft_lstnew.c $(HEADER)
	$(COMPILE) ft_lstnew.c

ft_lstdelone.o: ft_lstdelone.c $(HEADER)
	$(COMPILE) ft_lstdelone.c

ft_lstdel.o: ft_lstdel.c $(HEADER)
	$(COMPILE) ft_lstdel.c

ft_lstadd.o: ft_lstadd.c $(HEADER)
	$(COMPILE) ft_lstadd.c

ft_lstiter.o: ft_lstiter.c $(HEADER)
	$(COMPILE) ft_lstiter.c

ft_lstmap.o: ft_lstmap.c $(HEADER)
	$(COMPILE) ft_lstmap.c

ft_iswhitespace.o: ft_iswhitespace.c $(HEADER)
	$(COMPILE) ft_iswhitespace.c

ft_skipwhitespace.o: ft_skipwhitespace.c $(HEADER)
	$(COMPILE) ft_skipwhitespace.c

ft_strupper.o: ft_strupper.c $(HEADER)
	$(COMPILE) ft_strupper.c

ft_strlower.o: ft_strlower.c $(HEADER)
	$(COMPILE) ft_strlower.c

ft_intiter.o: ft_intiter.c $(HEADER)
	$(COMPILE) ft_intiter.c

ft_strsplit.o: ft_strsplit.c $(HEADER)
	$(COMPILE) ft_strsplit.c

btree_create_node.o: btree_create_node.c $(HEADER)
	$(COMPILE) btree_create_node.c

btree_apply_prefix.o: btree_apply_prefix.c $(HEADER)
	$(COMPILE) btree_apply_prefix.c

btree_apply_infix.o: btree_apply_infix.c $(HEADER)
	$(COMPILE) btree_apply_infix.c

btree_apply_suffix.o: btree_apply_suffix.c $(HEADER)
	$(COMPILE) btree_apply_suffix.c

ft_findchar.o: ft_findchar.c $(HEADER)
	$(COMPILE) ft_findchar.c

ft_realloc.o: ft_realloc.c $(HEADER)
	$(COMPILE) ft_realloc.c

get_next_line.o: get_next_line.c $(HEADER)
	$(COMPILE) get_next_line.c

ft_itoa_base.o: ft_itoa_base.c $(HEADER)
	$(COMPILE) ft_itoa_base.c

ft_utoa_base.o: ft_utoa_base.c $(HEADER)
	$(COMPILE) ft_utoa_base.c

ft_atoi_base.o: ft_atoi_base.c $(HEADER)
	$(COMPILE) ft_atoi_base.c

list_free.o: list_free.c $(HEADER)
	$(COMPILE) list_free.c

get_list_size.o: get_list_size.c $(HEADER)
	$(COMPILE) get_list_size.c

copy_list.o: copy_list.c $(HEADER)
	$(COMPILE) copy_list.c

$(NAME): $(OBJ_NAME)
	$(AR) $(NAME) $(OBJ_NAME)
	$(RLIB) $(NAME)

clean:
	$(RM) $(OBJ_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all
