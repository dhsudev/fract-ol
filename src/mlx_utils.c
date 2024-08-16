/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:52:31 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 19:32:19 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int	handle_keys(int keysym, t_fractal *fractal)
{
	if (keysym == ESC)
		die(fractal, 0);
	else if (keysym == PLUS)
		fractal->iterations += 2;
	else if (keysym == MINUS)
		fractal->iterations -= 2;
	ft_printf(YELLOW "Debug: " RESET "The %d key has been pressed\n\n", keysym);
	pixel_populate(fractal);
	return (0);
}

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->data->mlx, fractal->img->img);
	fractal->img->img = mlx_new_image(fractal->data->mlx, WIDTH, HEIGHT);
	fractal->img->addr = mlx_get_data_addr(fractal->img->img,
			&fractal->img->bits_per_pixel, &fractal->img->line_length,
			&fractal->img->endian);
	pixel_populate(fractal);
}

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->data->mlx, fractal->img->img);
	mlx_destroy_window(fractal->data->mlx, fractal->data->window);
	mlx_destroy_display(fractal->data->mlx);
	free(fractal->data->mlx);
	exit(0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *fractal)
{
	if (key_code == 4)
		fractal->zoom -= 0.1;
	else if (key_code == 5)
		fractal->zoom += 0.1;
	pixel_populate(fractal);
	(void)x;
	(void)y;
	(void)fractal;
	return (0);
}
