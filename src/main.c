/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:49 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 19:58:42 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_fractal	*get_fractals(void)
{
	static t_fractal	array[3] = {
	{"mandelbrot", NULL, NULL, 40, 1, 0, 0, RGB_WHITE, 0},
	{"julia", NULL, NULL, 40, 1, 0, 0, RGB_WHITE, 1},
	{NULL, NULL, NULL, 0, 0, 0, 0, 0, 0}
	};

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

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_mlx_img	img;
	t_fractal	fractal;
	int			atod_flag;

	if (argc < 2)
		die(0, ERROR_MSG);
	fractal = fractal_match(argv[1]);
	if (!fractal.name)
		die(0, ERROR_MSG);
	if (!ft_strcmp(fractal.name, "julia"))
	{
		if (argc != 4)
			die(0, ERROR_MSG);
		atod_flag = 0;
		fractal.c_julia_x = ft_atod(argv[2], &atod_flag);
		fractal.c_julia_y = ft_atod(argv[3], &atod_flag);
		if (atod_flag == 1)
			die(0, ERROR_MSG_JULIA);
	}
	else if (argc > 2)
		die(0, ERROR_MSG_MBROT);
	init(&fractal, &img, &data);
	mlx_loop(data.mlx);
	return (0);
}
