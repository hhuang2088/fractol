#include "fractal.h"

static t_rgb			*init_rgb(void)
{
	t_rgb		*rgb;

	rgb = (t_rgb*)malloc(sizeof(rgb));
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	return (rgb);
}

t_state						*state_init(int pattern_number)
{
	t_state		*state;

	if (!(state = (t_state*)malloc(sizeof(t_state))))
		return (NULL);
	state->mlx = NULL;
	state->win = NULL;
	state->img = NULL;
	state->img_addr = NULL;
	state->height = 500;
	state->width = 500;
	state->bits_per_pixel = 0;
	state->size_line = 0;
	state->endian = 0;
	state->rgb = init_rgb();
	state->pad_x = 0;
	state->pad_y = 0;
	state->x_displacement = 0;
	state->y_displacement = 0;
	state->zoom = 1;
	state->mouse_x = 0;
	state->mouse_y = 0;
	state->newton_radius = 5.0;
	state->newton_side = 2.0;
	if (pattern_number == 1)
	{
		state->pattern_draw = mandelbrot_draw;
		state->max = 10;
		state->x_displacement_sensitivity = 10;
		state->y_displacement_sensitivity = 10;
		state->max_value_sensitivity = 0.5;
		state->zoom_value_sensitivity = 20;
	}
	else if (pattern_number == 2)
	{
		state->pattern_draw = julia_draw;
		state->max = 15;
		state->x_displacement_sensitivity = .05;
		state->y_displacement_sensitivity = .05;
		state->max_value_sensitivity = 1;
		state->zoom_value_sensitivity = .1;
	}
	else if (pattern_number == 3)
	{
		state->pattern_draw = newton_draw;
		state->max = 2;
		state->x_displacement_sensitivity = 10;
		state->y_displacement_sensitivity = 10;
		state->max_value_sensitivity = 1;
		state->zoom_value_sensitivity = 20;
	}
	return (state);
}
