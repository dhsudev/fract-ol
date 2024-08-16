/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:29:11 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 20:04:54 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>

// WINDOW INFO
# define WIDTH 800
# define HEIGHT 800

// To check if a iteration is outside the fractal
// 2 ^ 2 (the range of the complex plane)
# define OUTBOUNDED 4

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_mlx_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_img;
typedef struct s_mlx_data
{
	void		*mlx;
	void		*window;
	t_mlx_img	*img;
}				t_mlx_data;
typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;
typedef struct s_fractal
{
	char		*name;
	t_mlx_img	*img;
	t_mlx_data	*data;
	int			iterations;
	double		zoom;
	double		c_julia_x;
	double		c_julia_y;
	int			base_color;
	int			mouse;
}				t_fractal;

// MLX stuff
void			my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
int				handle_keys(int keysym, t_fractal *fractal);
int				freeall(t_fractal *fractal);
int				mouse_hook(int key_code, int x, int y, t_fractal *fractal);
void			fractalsetup(t_fractal *fractal);
void			pixel_populate(t_fractal *fractal);

// Math stuff
t_complex		power(t_complex z);
t_complex		sum(t_complex z1, t_complex z2);
double			map(double n, double new_min, double new_max, double prev_max);
void			init(t_fractal *fractal, t_mlx_img *img, t_mlx_data *data);
int				die(t_fractal *fractal, char *message);

// KEYS
# define ESC 65307
# define MINUS 65453
# define PLUS 65451
# define NUM_ENTER 65293

// RGB COLORS
# define RGB_WHITE 0xFFFFFF
# define RGB_BLACK 0x000000

// COLOR ESCAPE CODES
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define ERROR_MSG \
	"Invalid arguments\nAvalible fractals are: \
		\n\t\033[0;36m~ \033[0mjulia \033[0;33m{start x} {start y}\033[0;33m\
		\n\t\033[0;36m~ \033[0mmandelbrot"
# define ERROR_MSG_JULIA "Invalid arguments. Julia needs 2 starting positions\n"
# define ERROR_MSG_MBROT "Invalid arguments. Mandelbrot has no arguments\n"
#endif
