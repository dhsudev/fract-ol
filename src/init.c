/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:07:10 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 19:59:13 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	die(t_fractal *fractal, char *message)
{
	if (!fractal)
		ft_printf(RED "Error: " RESET "%s\n", message);
	else
		freeall(fractal);
	exit(1);
}

static void	hoooks_init(t_fractal *fractal)
{
	mlx_hook(fractal->data->window, 17, 0L, die, fractal);
	mlx_key_hook(fractal->data->window, handle_keys, fractal);
	mlx_mouse_hook(fractal->data->window, mouse_hook, fractal);
}

void	init(t_fractal *fractal, t_mlx_img *img, t_mlx_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(1);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol by lua");
	if (data->window == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		freeall(fractal);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	fractal->img = img;
	fractal->data = data;
	hoooks_init(fractal);
	fractalsetup(fractal);
}
