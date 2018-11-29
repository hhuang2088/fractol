# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/20 23:19:16 by hehuang           #+#    #+#              #
#    Updated: 2017/06/02 12:49:43 by hehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ./inc/
HEADER_FILE = $(HEADER)ft_printf.h $(LIBHEAD)
SRCDIR = ./src/
LIBDIR = ../libft/
LIBHEAD = $(LIBDIR)libft.h
LIB = $(LIBDIR)libft.a
LIBINC = -I$(LIBDIR)
LIBLINK = -L$(LIBDIR) -lft
FLAGS = -g -Wall -Wextra -Werror -c
CC = gcc
FLAGS_TEST = -g -c
OPTIONS = -I$(HEADER) $(FLAGS)
COMPILE = $(CC) $(OPTIONS)
SRC_FILES = ft_printf.c \
			process_tag.c \
			handle_chars_and_strings.c \
			handle_tag.c \
			flag_util.c \
			init_tag.c \
			create_width.c \
			precision_itoa.c \
			precision_utoa.c \
			cast_int_with_length.c \
			get_modifiers.c \
			get_length.c \
			ft_putwi.c \
			ft_putws.c \
			ft_wcslen.c \
			ft_wstrlen.c \
			ft_wstrnew.c \
			ft_wstrcpy.c \
			ft_wstrncpy.c \
			ft_wcharlen.c \
			handle_number_util.c \
			handle_unsigned.c \
			handle_decimal.c \
			handle_oct.c \
			handle_hex.c \
			handle_invalid.c \
			handle_wchar_and_wstr.c
AR = ar rc
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
FILES = $(SRC_FILES)
OBJ_NAME = $(FILES:.c=.o)
RLIB = ranlib

.PHONY: all clean fclean re

all: libft $(NAME)

libft: $(LIB)

$(LIB):
	make -C $(LIBDIR)

ft_printf.o: $(SRCDIR)ft_printf.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_printf.c

process_tag.o: $(SRCDIR)process_tag.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)process_tag.c

handle_chars_and_strings.o: $(SRCDIR)handle_chars_and_strings.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_chars_and_strings.c

handle_tag.o: $(SRCDIR)handle_tag.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_tag.c

flag_util.o: $(SRCDIR)flag_util.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)flag_util.c

init_tag.o: $(SRCDIR)init_tag.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)init_tag.c

create_width.o: $(SRCDIR)create_width.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)create_width.c

precision_itoa.o: $(SRCDIR)precision_itoa.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)precision_itoa.c

precision_utoa.o: $(SRCDIR)precision_utoa.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)precision_utoa.c

cast_int_with_length.o: $(SRCDIR)cast_int_with_length.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)cast_int_with_length.c

get_modifiers.o: $(SRCDIR)get_modifiers.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)get_modifiers.c

get_length.o: $(SRCDIR)get_length.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)get_length.c

ft_putwi.o: $(SRCDIR)ft_putwi.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_putwi.c

ft_putws.o: $(SRCDIR)ft_putws.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_putws.c

ft_wcslen.o: $(SRCDIR)ft_wcslen.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_wcslen.c

ft_wstrlen.o: $(SRCDIR)ft_wstrlen.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_wstrlen.c

ft_wstrnew.o: $(SRCDIR)ft_wstrnew.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_wstrnew.c

ft_wstrcpy.o: $(SRCDIR)ft_wstrcpy.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_wstrcpy.c

ft_wstrncpy.o: $(SRCDIR)ft_wstrncpy.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_wstrncpy.c

ft_wcharlen.o: $(SRCDIR)ft_wcharlen.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)ft_wcharlen.c

handle_number_util.o: $(SRCDIR)handle_number_util.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_number_util.c

handle_unsigned.o: $(SRCDIR)handle_unsigned.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_unsigned.c

handle_decimal.o: $(SRCDIR)handle_decimal.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_decimal.c

handle_oct.o: $(SRCDIR)handle_oct.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_oct.c

handle_hex.o: $(SRCDIR)handle_hex.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_hex.c

handle_invalid.o: $(SRCDIR)handle_invalid.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_invalid.c

handle_wchar_and_wstr.o: $(SRCDIR)handle_wchar_and_wstr.c $(HEADER_FILE)
	$(COMPILE) $(SRCDIR)handle_wchar_and_wstr.c

$(NAME): $(OBJ_NAME)
	$(AR) $(NAME) $(OBJ_NAME)
	$(RLIB) $(NAME)

test:
	$(CC) $(OPTIONS) test.c -c
	$(CC) $(NAME) $(OBJ_NAME) $(LIBLINK) test.o -o hello

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

cleantest:
	rm -f test.o
	rm -f hello

re: fclean all
