/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:52:31 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 03:03:52 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_keys(int keysym, t_mlx_data *data)
{
    if (keysym == ESC)
    {
        ft_printf(YELLOW "Debug: " RESET "The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(0);
    }
    ft_printf(YELLOW "Debug: " RESET "The %d key has been pressed\n\n", keysym);
    return (0);
}

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->data->mlx, fractal->img->img);
	fractal->img->img = mlx_new_image(fractal->data->mlx, WIDTH, HEIGHT);
	fractal->img->addr = mlx_get_data_addr(fractal->img->img, &fractal->img->bits_per_pixel,
			&fractal->img->line_length, &fractal->img->endian);
	pixel_populate(fractal);
	mlx_put_image_to_window(fractal->data->mlx, fractal->data->window, fractal->img->img, 0, 0);
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
	(void)key_code;
	(void)x;
	(void)y;
	(void)fractal;
	return 0;
}
