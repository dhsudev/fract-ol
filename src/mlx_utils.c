/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:52:31 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/15 22:10:05 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_mlx_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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
