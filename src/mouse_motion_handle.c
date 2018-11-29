#include "fractal.h"

int		mouse_motion_handle(int x, int y, t_state *state)
{
	mlx_clear_window(state->mlx, state->win);
	if (x > state->mouse_x)
		state->max += FRACTAL_MAX_VALUE_CHANGE_PER_MOUSE_MOVEMENT * state->max_value_sensitivity;
	else if (x < state->mouse_x)
		state->max -= FRACTAL_MAX_VALUE_CHANGE_PER_MOUSE_MOVEMENT * state->max_value_sensitivity;
	state->mouse_x = x;
	state->mouse_y = y;
	state->pattern_draw(state);
	mlx_put_image_to_window(state->mlx, state->win,
		state->img, state->pad_x, state->pad_y);
	return (0);
}
