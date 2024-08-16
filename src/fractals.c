/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:37:28 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 03:11:32 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	set_c(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strcmp(fractal->name, "julia"))
	{
		c->x = fractal->c_julia->x;
		c->y = fractal->c_julia->y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

/*static int get_color(int iterations, int max_iterations, int base_color)
{
	int red;
	int blue;
	int green;
	int color;

	red = (base_color >> 16) & 0xFF;
	green = (base_color >> 8) & 0xFF;
    blue = base_color & 0xFF;
	color = red | green | blue;
	color = map(iterations, RGB_BLACK, RGB_WHITE, 0, max_iterations);
	return (color);
}*/

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
static void pixel_calc(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	//int color;

	z.x = (map(y, -2, +2, 0, WIDTH) * fractal->zoom);
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom);

	set_c(&z, &c, fractal);
	ft_printf("(%d,%d)\n", x , y);
	while(i < fractal->iterations)
	{
		z = sum(power(z), c);
		if((z.x * z.x) + (z.y * z.y) > OUTBOUNDED)
		{
			//color = get_color(i, fractal->iterations, fractal->base_color);
			my_mlx_pixel_put(fractal->img, x, y, RGB_BLACK);
			return ;
		}
		i++;
	}

	my_mlx_pixel_put(fractal->img, x, y, RGB_WHITE);
}


void	pixel_populate(t_fractal *fractal)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
			pixel_calc(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->data->mlx,
							fractal->data->window,
							fractal->img,
							0, 0);
}
