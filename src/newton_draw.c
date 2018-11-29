#include "fractal.h"

static int		newton_fits_in_set(double x, double y, t_state *state)
{
	if ((x-state->x_displacement)*(x-state->x_displacement) +
	(y-state->y_displacement)*(y-state->y_displacement) >
	state->newton_radius)
		return (1);
	return (0);
}

static void 	newton_set_pixel_color(t_state *state, int x, int y, int iteration)
{
	state->rgb->r = 255 * !newton_fits_in_set(x, y, state);
	state->rgb->g = ((iteration * 5) % 256) * newton_fits_in_set(x, y, state) +
							((iteration * 10) % 256) * !newton_fits_in_set(x, y, state);
	state->rgb->b = (50 + (iteration * 5) % 206) * newton_fits_in_set(x, y, state);
}

void newton_draw(t_state *state)
{
	int col;
	int row;
	int iteration;
	double x;
	double y;
	double x_new;
	double y_new;
	double cRe;
	double cIm;

	col = 0;
	while (col < state->width)
	{
		cRe = -state->newton_side + 2*state->newton_side/state->width*col;
		row = 0;
		while (row < state->height)
		{
			cIm = -state->newton_side + 2*state->newton_side/state->height*row;
			x = cRe;
			y = cIm;
			iteration = 0;
			while (iteration < state->max)
			{
				x_new = 5*x/6.0 - x*(x*x*x*x - 10*x*x*y*y +5*y*y*y*y)/(x*x+y*y)/(x*x+y*y)/(x*x+y*y)/(x*x+y*y)/(x*x+y*y)/6.0;
				y_new = 5*y/6.0 + y*(5*x*x*x*x - 10*x*x*y*y + y*y*y*y)/(x*x+y*y)/(x*x+y*y)/(x*x+y*y)/(x*x+y*y)/(x*x+y*y)/6.0;
				x = x_new;
				y = y_new;
				newton_set_pixel_color(state, x, y, iteration);
				pixel_draw_single_byte(state, col, row);
				++iteration;
			}
			++row;
		}
		++col;
	}
}
