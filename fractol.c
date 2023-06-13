/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/06/13 15:04:20 by arcarval         ###   ########.fr       */
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

static void set_pixel_color(char *buf, int x, int y, int color)
{
	buf[x * 4 + y * WINDOW_WIDTH * 4] = color;
	buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = color >> 8;
	buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = color >> 16;
	buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = color >> 24;
}

void render(void *mlx, void *mlx_win)
{
	int x;
	int y;
	double pr;
	double pi;
	// int nb_iter;
	double	min_r = -4.0;
	double	max_r = 4.0;
	double	min_i = -4.0;
	double	max_i = min_i + (max_r - min_r) * WINDOW_HEIGHT / WINDOW_WIDTH;
	void	*img = NULL;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buf;

	mlx_clear_window(mlx, mlx_win);
	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	buf = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			pr = min_r + (double)x * (max_r - min_r) / WINDOW_WIDTH;
			pi = max_i + (double)y * (min_i - max_i) / WINDOW_HEIGHT;
			// nb_iter = calculate_fractal(f, pr, pi);
			set_pixel_color(buf, x, y, 0x00FF00AA);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	render(mlx, mlx_win);
	mlx_key_hook(mlx_win, key_events_handler, mlx);
	mlx_loop(mlx);
}
