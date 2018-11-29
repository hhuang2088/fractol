#ifndef FRACTAL_H
# define FRACTAL_H
# include <math.h>
# include <limits.h>
# include "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/Headers/Events.h"
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/inc/ft_printf.h"
# define PIXEL_DISPLACEMENT_PER_KEY_PRESS 1
# define FRACTAL_MAX_VALUE_CHANGE_PER_KEY_PRESS 1
# define FRACTAL_MAX_VALUE_CHANGE_PER_MOUSE_MOVEMENT 1
# define ZOOM_CHANGE_PER_KEY_PRESS 1
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_BUTTON_LEFT 1
# define MOUSE_BUTTON_RIGHT 2
# define BYTE_SIZE 8
# define KEYBOARD_COMMA 43
# define KEYBOARD_PERIOD 47
# define KEYBOARD_DASH 27
# define KEYBOARD_EQUAL 24

typedef struct 			s_rgb
{
	int		r;
	int		g;
	int		b;
}						t_rgb;

typedef struct 				s_state
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			pad_x;
	int			pad_y;
	int			height;
	int			width;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	int			size_line;
	int			endian;
	double		max;
	double		newton_radius;
	double		newton_side;
	double		x_displacement;
	double		y_displacement;
	double		zoom;
	double		max_value_sensitivity;
	double		x_displacement_sensitivity;
	double		y_displacement_sensitivity;
	double		zoom_value_sensitivity;
	int			mouse_x;
	int			mouse_y;
	void 		(*pattern_draw)(struct s_state *state);
	t_rgb		*rgb;
}							t_state;

t_state		*state_init(int pattern_number);
int			arg_handle(int ac, char **av);
void 		pixel_draw_single_byte(t_state *state, int col, int row);
int			calculate_int_radius(int x1, int y1, int x2, int y2);
void		mandelbrot_draw(t_state *state);
void 		julia_draw(t_state *state);
void 		newton_draw(t_state *state);
int			keyboard_input_handle(int input, t_state *state);
int			keyboard_release_handle(int input, t_state *state);
int			mouse_input_handle(int input, int x, int y, t_state *state);
int			mouse_motion_handle(int x, int y, t_state *state);

#endif
