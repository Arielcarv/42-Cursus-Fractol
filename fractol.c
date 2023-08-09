/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/09 17:50:50 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_pixel_color(char *buf, int x, int y, int color)
{
	int	red = 0xFF2200;
	int	green = 0x0000FF;
	int	yellow = 0xFFFF00;
	int	blue = 0x0000FF;
	// int	red = 300;
	// int	green = 0xFF << 24 | 255 << 16 | 0 << 8 | 0;
	// ft_printf("GREEN %d, YELLOW: %d\n", green, yellow);
	if ( y == 0 || y == WINDOW_HEIGHT - 1 || x == 0 || x == WINDOW_WIDTH - 1)
	{
		// ft_printf("BUFFER: %d\n", x * 4 + y * WINDOW_WIDTH * 4);
		// buf[x * 4 + y * WINDOW_WIDTH * 4] = 255;		//blue;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = 255;	//green;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = 255;	//red;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = 255;	//black;
		buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = 255 >> 24;	//black;
	}
	else
	{
		// buf[x * 4 + y * WINDOW_WIDTH * 4] = 255;			//blue;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = 0xFF;	// green
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = 0xFF;	// red
		buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = 0xFF;	//black
	}
}

int color(int i)
{
	int n;

	n = 3;
	while (--n >= 1)
		i = (i * 3269) / 61;
	return (i);
}

void my_mlx_pixel_put(t_fractol *vars, int x, int y, int color)
{
	char *dest;

	dest = vars->buff + (y * vars->line_size + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int interations(t_fractol *vars)
{
	double z_temp;

	vars->interation = 0;
	while (vars->interation < 200)
	{
		z_temp = vars->z.re;
		vars->z.re = ((vars->z.re * vars->z.re) - (vars->z.im * vars->z.im)) + vars->c.re;
		vars->z.im = (2 * z_temp * vars->z.im) + vars->c.im;
		if (((vars->z.re * vars->z.re) + (vars->z.im * vars->z.im)) > 4)
			break;
		vars->interation++;
	}
	return (vars->interation);
}

int mandelbrot(t_fractol *vars)
{
	int y;
	int x;
	int interation = 0;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		vars->c.im = 0 + (y - WINDOW_HEIGHT / 2.0) * 4.0 / (WINDOW_HEIGHT / 1);
		while (x < WINDOW_WIDTH)
		{
			vars->c.re = 0 + (x - WINDOW_WIDTH / 2.0) * 4.0 / (WINDOW_WIDTH / 1);
			vars->z.re = 0;
			vars->z.im = 0;
			vars->interation = interations(vars);
			if (vars->interation != 200)
				// put_color(vars);
				my_mlx_pixel_put(vars, x, y, color(vars->interation));
			x++;
		}
		y++;
	}
	return (0);
}

void	render_fractal(t_fractol *params)
{
	int	x;
	int	y;

	mlx_clear_window(params->mlx, params->mlx_win);
	params->img = mlx_new_image(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	params->buff = mlx_get_data_addr(params->img, &params->bits_per_pixel,
			&params->line_size, &params->endian);
	// y = -1;
	// while (++y < WINDOW_HEIGHT)
	// {
	// 	x = -1;
	// 	while (++x < WINDOW_WIDTH)
	// 	{
	// 		set_pixel_color(params->buff, x, y, 0xFFF);
	// 	}
	// }
	mandelbrot(params);
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	params;

	if (argc != 2)
	{
		ft_printf("Usage: ./fractol <fractal_name>\n");
		return (0);
	}
	initialize_params(&params);
	open_window(&params);
	render_fractal(&params);
	mlx_hook(params.mlx_win, CLOSE_BUTTON, 0, close_window, params.mlx);
	mlx_key_hook(params.mlx_win, key_events_handler, params.mlx);
	mlx_mouse_hook(params.mlx_win, mouse_events_handler, params.mlx);
	mlx_loop(params.mlx);
	return (0);
}
