/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:34:49 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/06/25 19:38:21 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

typedef struct s_mlx_data
{
    void	*connection;
    void	*window;
}               t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->connection, data->window);
        mlx_destroy_display(data->connection);
        free(data->connection);
        exit(1);
    }
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

int main(void)
{
	t_mlx_data data;

	data.connection = mlx_init();
	if(!data.connection)
		return(1);
	data.window = mlx_new_window(data.connection, 
								WIDTH, HEIGHT, "Fractol by lua 🦦");
	if(!data.window)
	{
		mlx_destroy_display(data.connection);
		free(data.connection);
		return(1);
	}

	mlx_key_hook(data.window, 
                handle_input,
                &data);

	mlx_loop(data.connection);
}
