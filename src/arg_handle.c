#include "fractal.h"

static void 	arg_display_usage(void)
{
	ft_printf("Usage: ./fractol [Number]\n");
	ft_printf("|Number|--------Patterns-------|\n");
	ft_printf("| 1    | Julia                 |\n");
	ft_printf("| 2    | Mandelbrot            |\n");
	ft_printf("| 3    | Newton                |\n");
	ft_printf("|------------------------------|\n");
}

int		arg_handle(int ac, char **av)
{
	if (ac != 2 && av)
		arg_display_usage();
	else
	{
		if (!ft_strcmp(av[1], "1"))
			return (1);
		else if (!ft_strcmp(av[1], "2"))
			return (2);
		else if (!ft_strcmp(av[1], "3"))
			return (3);
	}
	return (0);
}
