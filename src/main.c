#include "fractal.h"

int		main(int ac, char **av)
{
	t_state				*state;
	int						i;
	int						pattern_number;

	i = 0;
	pattern_number = arg_handle(ac, av);
	if (!pattern_number)
		return (0);
	if (!(state = state_init(pattern_number)))
		return (0);
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, state->width, state->height, "fractol");
	state->img = mlx_new_image(state->mlx, state->width, state->height);
	state->img_addr = mlx_get_data_addr(
	state->img, &state->bits_per_pixel, &state->size_line, &state->endian);
	state->bytes_per_pixel = state->bits_per_pixel / (sizeof(char) * BYTE_SIZE);
	state->pattern_draw(state);
	mlx_put_image_to_window(state->mlx, state->win,
		state->img, state->pad_x, state->pad_y);
	mlx_hook(state->win, 6, 0, mouse_motion_handle, state);
	mlx_mouse_hook(state->win, mouse_input_handle, state);
	mlx_hook(state->win, 2, 0, keyboard_input_handle, state);
//		mlx_hook(state->win, 3, 0, keyboard_release_handle, state);
	mlx_loop(state->mlx);
	return (0);
}
