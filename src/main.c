/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:49 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 03:03:21 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_fractal	*get_fractals(void)
{
	static t_fractal	array[3] = 
		{{"mandelbrot", NULL, NULL, 10, 1, NULL, RGB_WHITE, 0},
		{"julia",		NULL, NULL, 10, 1, NULL, RGB_WHITE, 1},
		{NULL, 			NULL, NULL, 0, 0, NULL, 0, 0}};

	return (array);
}

static t_fractal	fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (f[i]);
		i++;
	}
	return (f[i]);
}

int	die(char *message, t_fractal *fractal)
{
	if (message && *message)
		ft_printf(RED "Error: " RESET "%s\n", message);
	if(fractal)
		freeall(fractal);
	exit(1);
}

void init(t_fractal *fractal, t_mlx_img *img, t_mlx_data *data)
{
	fractal->img = img;
	fractal->data = data;
	fractal->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (fractal->img == NULL)
		freeall(fractal);
	fractal->img->addr = mlx_get_data_addr(fractal->img->img, &fractal->img->bits_per_pixel,
		&fractal->img->line_length, &fractal->img->endian);	
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_mlx_img	img;
	t_fractal	fractal;

	if (argc < 2)
		die(ERROR_MSG, 0);
	fractal = fractal_match(argv[1]);
	if (!fractal.name)
		die(ERROR_MSG, 0);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.window = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol by lua");
	if (!data.window)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	init(&fractal, &img, &data);
	mlx_hook(data.window, 17, 0L, die, &fractal);
	mlx_mouse_hook(data.window, mouse_hook, &fractal);
	mlx_key_hook(data.window, handle_keys, &data);
	pixel_populate(&fractal);
	mlx_loop(data.mlx);
	return (0);
}
