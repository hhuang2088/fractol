#include "fractal.h"

static void 				mandelbrot_set_pixel_color(int iteration, t_state *state)
{

	state->rgb->r = (iteration * 5) % 256;
	state->rgb->g = (iteration * 10) % 256 * (iteration < state->max);
	state->rgb->b = 255 * (iteration < state->max);
}

void								mandelbrot_draw(t_state *state)
{
	int		row;
	int		col;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	double	x_new;
	double	y_new;
	int			iteration;

	row = 0;
	while (row < state->height)
	{
		col = 0;
		while (col < state->width)
		{
			x = 0;
			y = 0;
			c_re = (((col - state->x_displacement) - state->width / 2.0) * 4.0) / (state->width + state->zoom);
			c_im = (((row - state->y_displacement) - state->height / 2.0) * 4.0) / (state->width + state->zoom);
			iteration = 0;
			while (x * x + y * y <= 4 && iteration < state->max)
			{
				x_new = x * x - y * y + c_re;
				y_new = 2 * x * y + c_im;
				x = x_new;
				y = y_new;
				++iteration;
			}
			mandelbrot_set_pixel_color(iteration, state);
			pixel_draw_single_byte(state, col, row);
			++col;
		}
		++row;
	}
}
