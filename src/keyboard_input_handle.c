#include "fractal.h"

static int 	handle_input_helper(int input, t_state *state)
{
	if (input == 53)
	{
		ft_putendl("Quitting Program.");
		mlx_destroy_image (state->mlx, state->img);
		mlx_destroy_window(state->mlx, state->win);
		free(state->mlx);
		free(state->rgb);
		free(state);
		exit(0);
	}
	ft_printf("Key pressed: %d\n", input);
	state->pattern_draw(state);
	mlx_put_image_to_window(state->mlx, state->win,
		state->img, state->pad_x, state->pad_y);
	return (0);
}

int		keyboard_input_handle(int input, t_state *state)
{
	mlx_clear_window(state->mlx, state->win);
	if (input == kVK_DownArrow)
		state->y_displacement += PIXEL_DISPLACEMENT_PER_KEY_PRESS * state->y_displacement_sensitivity;
	else if (input == kVK_UpArrow)
		state->y_displacement -= PIXEL_DISPLACEMENT_PER_KEY_PRESS * state->y_displacement_sensitivity;
	else if (input == kVK_RightArrow)
		state->x_displacement += PIXEL_DISPLACEMENT_PER_KEY_PRESS * state->x_displacement_sensitivity;
	else if (input == kVK_LeftArrow)
		state->x_displacement -= PIXEL_DISPLACEMENT_PER_KEY_PRESS * state->x_displacement_sensitivity;
	else if (input == KEYBOARD_EQUAL)
		state->max += FRACTAL_MAX_VALUE_CHANGE_PER_KEY_PRESS * state->max_value_sensitivity;
	else if (input == KEYBOARD_DASH)
		state->max -= FRACTAL_MAX_VALUE_CHANGE_PER_KEY_PRESS * state->max_value_sensitivity;
	else if (input == KEYBOARD_PERIOD)
		state->zoom += ZOOM_CHANGE_PER_KEY_PRESS * state->zoom_value_sensitivity;
	else if (input == KEYBOARD_COMMA)
		state->zoom -= ZOOM_CHANGE_PER_KEY_PRESS * state->zoom_value_sensitivity;
	return (handle_input_helper(input, state));
}
