/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:37:28 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 19:59:45 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	set_c(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->c_julia_x;
		c->y = fractal->c_julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static int	get_color(int iterations, int i)
{
	t_rgb	color;
	int		final_color;

	iterations += i;
	color.r = (iterations * 8) % 256;
	color.g = (iterations * 4) % 256;
	color.b = (iterations * 2) % 256;
	if (iterations % 2 == 0)
		color.r = 255 - color.r;
	if (iterations % 3 == 0)
		color.g = 255 - color.g;
	if (iterations % 5 == 0)
		color.b = 255 - color.b;
	final_color = (color.r << 16) | (color.g << 8) | color.b;
	return (final_color);
}

/*
 * Paints the pixel depending of the iterations and the fractal.
 * It does it by apling the formula:
 * 						f(z) = z^2 + c
 * Where:
 * 	~ z is actual pos (we need to map from pixel to complex map)
 *  ~ c in mandelbrot is z0 and in julia the given by arguments
 *
 *  Then we use pitagoras to know if its outbounded
 */
static void	pixel_calc(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom);
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom);
	set_c(&z, &c, fractal);
	i = 0;
	while (i < fractal->iterations)
	{
		z = sum(power(z), c);
		if ((z.x * z.x) + (z.y * z.y) > OUTBOUNDED)
		{
			color = get_color(fractal->iterations, i);
			my_mlx_pixel_put(fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(fractal->img, x, y, fractal->base_color);
}

void	pixel_populate(t_fractal *fractal)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			pixel_calc(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->data->mlx, fractal->data->window,
		fractal->img->img, 0, 0);
}
