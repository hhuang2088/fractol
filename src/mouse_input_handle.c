#include "fractal.h"

int		mouse_input_handle(int input, int x, int y, t_state *state)
{
	mlx_clear_window(state->mlx, state->win);
	if (input == MOUSE_WHEEL_UP)
		state->zoom -= ZOOM_CHANGE_PER_KEY_PRESS * state->zoom_value_sensitivity;
	else if (input == MOUSE_WHEEL_DOWN)
		state->zoom += ZOOM_CHANGE_PER_KEY_PRESS * state->zoom_value_sensitivity;
	else if (input == MOUSE_BUTTON_LEFT)
	{
		state->x_displacement -= (x - state->width/2);
		state->y_displacement -= (y - state->height/2);
	}
	else if (input == MOUSE_BUTTON_RIGHT)
	{
		state->x_displacement -= (x - state->width/2);
		state->y_displacement -= (y - state->height/2);
	}
	else if (!input)
		ft_printf("No Input\n");
	state->pattern_draw(state);
	ft_printf("input %d\n", input);
	mlx_put_image_to_window(state->mlx, state->win,
		state->img, state->pad_x, state->pad_y);
	return (0);
}
