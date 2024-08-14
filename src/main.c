/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:49 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/14 01:13:56 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx_img;
typedef struct s_mlx_data
{
    void		*mlx;
    void		*window;
	t_mlx_img	*img;
}               t_mlx_data;


int	handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == ESC)
    {
        ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(1);
    }
    ft_printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

static int deivid_was_here(void *param)
{
	(void)param;
	exit(2);
}

void	my_mlx_pixel_put(t_mlx_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int main(void)
{
	t_mlx_data data;
	t_mlx_img img;


	data.mlx = mlx_init();
	if(!data.mlx)
		return(1);
	data.window = mlx_new_window(data.mlx, 
								WIDTH, HEIGHT, "Fractol by lua");
	if(!data.window)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return(1);
	}
	mlx_hook(data.window, 17, 0L, &deivid_was_here, &data);
	mlx_key_hook(data.window, handle_input, &data);
	img.img = mlx_new_image(data.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	data.img = &img;
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0088);
	mlx_put_image_to_window(data.mlx, data.window, img.img, 0, 0);
	mlx_loop(data.mlx);
}
