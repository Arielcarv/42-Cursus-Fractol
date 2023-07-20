/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/07/20 13:04:19 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void *mlx)
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
		close_window(mlx);
	}
	else
	{
		printf("KEYSYM:%d\n", keysym);
		return (0);
	}
	return (1);
}

static void	set_pixel_color(char *buf, int x, int y, int color)
{
	// int	red = 0xFF2200;
	// int	green = 0x00FF55;
	// int	yellow = 0xFFFF00;
	int	blue = 0x0000FF;
	int	red = 300;
	int	green = 0xFF << 24 | 0 << 16 | 0 << 8 | 61440;
	int yellow = 0xFF << 24 | 1 << 16 | 1 << 8 | 0;
	// printf("GREEN %d, YELLOW: %d\n", green, yellow);
	if ( y == 0 || y == WINDOW_HEIGHT - 1 || x == 0 || x == WINDOW_WIDTH - 1)
	{
		// printf("BUFFER: %d\n", x * 4 + y * WINDOW_WIDTH * 4);
		// buf[x * 4 + y * WINDOW_WIDTH * 4] = 255 ;		//blue;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = 255 ;	//green;
		buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = 255 ;		//red;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = 255 ;	//black;
	}
	else
	{
		buf[x * 4 + y * WINDOW_WIDTH * 4] = blue;			//color;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = blue;	// green
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = blue;	// red
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = blue;	//black
	}
}

void	render_fractal(void *mlx, void *mlx_win)
{
	int		x;
	int		y;
	void	*img = NULL;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	mlx_clear_window(mlx, mlx_win);
	img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	buf = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			set_pixel_color(buf, x, y, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
}

int	main(void)
{
	t_fractol	params;
	void		*mlx_win;

	initialize_fractol(&params);
	open_window(&params);
	render_fractal(params.mlx, params.mlx_win);
	mlx_hook(params.mlx_win, CLOSE_BUTTON, 0, close_window, params.mlx);
	mlx_key_hook(params.mlx_win, key_events_handler, params.mlx);
	mlx_loop(params.mlx);
}
