/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/06/14 12:42:17 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_mlx(void *mlx)
{
	mlx_loop_end(mlx);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(0);
	return (0);
}

int	key_events_handler(int keysym, void *mlx)
{
	if (keysym == KEY_ESC)
	{
		close_mlx(mlx);
	}
	return (1);
}

static void	set_pixel_color(char *buf, int x, int y, int color)
{
	// buf[x * 4 + y * WINDOW_WIDTH * 4] = color;
	// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = color >> 4;
	// buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = color >> 16;
	// buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = color >> 24;

	// int	red = 0xFF2200;
	// int	green = 0x00FF55;
	// int	yellow = 0xFFFF00;
	int	blue = 0x0000FF;

	// if (x % 2 == 0 && y % 2 == 0)
	// 	buf[x * 4 + y * WINDOW_WIDTH * 4] = green;
	// else if (x % 2 == 0 && y % 2 != 0)
	// 	buf[x * 4 + y * WINDOW_WIDTH * 4] = yellow;
	// else if (x % 2 != 0 && y % 2 == 0)
	// 	buf[x * 4 + y * WINDOW_WIDTH * 4] = red;
	// else if (x % 2 != 0 && y % 2 != 0)
	// 	buf[x * 4 + y * WINDOW_WIDTH * 4] = color;

	int	red = 300;
	int	green = 0xFF << 24 | 0 << 16 | 0 << 8 | 61440;
	int yellow = 0xFF << 24 | 1 << 16 | 1 << 8 | 0;
	// printf("GREEN %d, YELLOW: %d\n", green, yellow);
	if ( y == 0 || y == WINDOW_HEIGHT - 1 || x == 0 || x == WINDOW_WIDTH - 1)
	{
		printf("BUFFER: %d\n", x * 4 + y * WINDOW_WIDTH * 4);
		// buf[x * 4 + y * WINDOW_WIDTH * 4] = 255 ;		//blue;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = 255 ;	//green;
		buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = 255 ;		//red;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = 255 ;	//black;
	}
	else
	{
		buf[x * 4 + y * WINDOW_WIDTH * 4] = blue;		//color;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = blue;		// green
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = blue;	// red
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = blue;	//black
	}
}

void	render_fractal(void *mlx, void *mlx_win)
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
			pr = min_r + x * (max_r - min_r) / WINDOW_WIDTH;
			pi = max_i + y * (min_i - max_i) / WINDOW_HEIGHT;
			// nb_iter = calculate_fractal(f, pr, pi);
			set_pixel_color(buf, x, y, 0xFF00AA);
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
	render_fractal(mlx, mlx_win);
	mlx_hook(mlx_win, CLOSE_BUTTON, 0, close_mlx, mlx);
	mlx_key_hook(mlx_win, key_events_handler, mlx);
	mlx_loop(mlx);
}
