/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/06/12 16:57:10 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events_handler(int keysym, void *mlx)
{
	if (keysym == KEY_ESC)
	{
		mlx_loop_end(mlx);
		mlx_destroy_display(mlx);
		free(mlx);
		exit(0);
		return (0);
	}
	return (1);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	mlx_key_hook(mlx_win, key_events_handler, mlx);
	mlx_loop(mlx);
}
