NAME = fractol
HEADER = ./inc/
SRCDIR = ./src/
FLAGS = -g -Wall -Wextra -Werror
CC = gcc
FILES = main.c state_init.c arg_handle.c pixel_util.c mandelbrot_draw.c \
				julia_draw.c keyboard_input_handle.c mouse_input_handle.c \
				mouse_motion_handle.c newton_draw.c
OPTIONS = -I$(HEADER) $(FLAGS)
LIBDIR = ./libft/
LIBFT = $(LIBDIR)libft.a
LIBLINK = -L$(LIBDIR) -lft
PFDIR = ./ft_printf/
PRINTF = $(PFDIR)ft_printf.a
PFLINK = -L$(PFDIR) -lftprintf
LIBMLXDIR = ./minilibx_macos/
LIBMLX = $(LIBMLXDIR)libmlx.a
LIBMLXLINK = -L$(LIBMLXDIR) -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit
SRC = $(addprefix $(SRCDIR), $(FILES))
OBJ = $(FILES:.c=.o)

.PHONY: all clean fclean re

all: libft printf libmlx $(NAME)

libft: $(LIBFT)

printf: $(PRINTF)

libmlx: $(LIBMLX)

$(LIBFT):
	make -C $(LIBDIR)

$(PRINTF):
	make -C $(PFDIR)

$(LIBMLX):
	make -C $(LIBMLXDIR)

main.o: $(SRCDIR)main.c $(HEADER)fractal.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)main.c

state_init.o: $(SRCDIR)state_init.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)state_init.c

arg_handle.o: $(SRCDIR)arg_handle.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)arg_handle.c

pixel_util.o: $(SRCDIR)pixel_util.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)pixel_util.c

keyboard_input_handle.o: $(SRCDIR)keyboard_input_handle.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)keyboard_input_handle.c

mouse_input_handle.o: $(SRCDIR)mouse_input_handle.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)mouse_input_handle.c

mouse_motion_handle.o: $(SRCDIR)mouse_motion_handle.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)mouse_motion_handle.c

mandelbrot_draw.o: $(SRCDIR)mandelbrot_draw.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)mandelbrot_draw.c

julia_draw.o: $(SRCDIR)julia_draw.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)julia_draw.c

newton_draw.o: $(SRCDIR)newton_draw.c $(HEADER)fractal.h
	$(CC) $(OPTIONS) -c $(SRCDIR)newton_draw.c

$(NAME): $(OBJ)
	$(CC) $(LIBLINK) $(PFLINK) $(LIBMLXLINK) $(OBJ) $(FRAMEWORK) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
