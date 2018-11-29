#include "fractal.h"

static void		pixel_endian_little_draw_single_byte(t_state *state, int pixel_location)
{
	state->img_addr[pixel_location] = (char)state->rgb->b;
	state->img_addr[pixel_location + 1] = (char)state->rgb->g;
	state->img_addr[pixel_location + 2] = (char)state->rgb->r;
	state->img_addr[pixel_location + 3] = (char)0;
}

static void		pixel_endian_big_draw_single_byte(t_state *state, int pixel_location)
{
	state->img_addr[pixel_location] = (char)0;
	state->img_addr[pixel_location + 1] = (char)state->rgb->r;
	state->img_addr[pixel_location + 2] = (char)state->rgb->g;
	state->img_addr[pixel_location + 3] = (char)state->rgb->b;
}

void 		pixel_draw_single_byte(t_state *state, int col, int row)
{
	int		pixel_location;

	pixel_location = (row * state->size_line) + (col * state->bytes_per_pixel);
	if (state->endian)
		pixel_endian_big_draw_single_byte(state, pixel_location);
	else
		pixel_endian_little_draw_single_byte(state, pixel_location);
}
