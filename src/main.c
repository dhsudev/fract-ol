/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:49 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/15 22:08:20 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_fractal	*get_fractals(void)
{
	static t_fractal	array[3] = {{"mandelbrot", 0}, {"julia", 1}, {NULL, 0}};

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

int	die(char *message, int error)
{
	if (error == 0)
		ft_printf(RED "Error: " RESET "%s\n", message);
	else
		exit(0);
	exit(1);
}

void	render(t_mlx_data *data, t_mlx_img *img)
{
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	my_mlx_pixel_put(img, 5, 5, 0x00FF0088);
	mlx_put_image_to_window(data->mlx, data->window, img->img, 0, 0);
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
	mlx_hook(data.window, 17, 0L, &die, &data);
	mlx_key_hook(data.window, handle_keys, &data);
	render(&data, &img);
	mlx_loop(data.mlx);
	return (0);
}
