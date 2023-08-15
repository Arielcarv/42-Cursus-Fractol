/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/15 20:11:21 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

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
	}
	else
	{
		// buf[x * 4 + y * WINDOW_WIDTH * 4] = 255;			//blue;
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 1] = 0xFF;	// green
		buf[x * 4 + y * WINDOW_WIDTH * 4 + 2] = 0xFF;	// red
		// buf[x * 4 + y * WINDOW_WIDTH * 4 + 3] = 0xFF;	//black
	}
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dest;

	dest = fractol->buff + (y * fractol->line_size + x * (fractol->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	color(t_fractol *params, int i)
{
	int	n;
	if (params->interations == 255)
		return (0);
	n = 3;
	while (--n >= 1)
		i = (i * 3263) / 61;
	return (i);
}

void	mandelbrot(t_fractol *params)
{
	int	x;
	int	y;
	double	p_re;
	double	p_im;

	params->min_re = -2.0;
	params->max_im = 2.0;
	p_re = params->min_re;
	p_im = params->max_im;
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		p_im -= ((fabs(params->max_im) + fabs(params->max_im)) / WINDOW_HEIGHT);
		x = -1;
		
		while (++x < WINDOW_WIDTH)
		{
			// printf("\nRESULT: %f", ((fabs(params->min_re) + fabs(params->min_re)) / WINDOW_HEIGHT));
			p_re += 0.001 + ((fabs(params->min_re) + fabs(params->min_re)) / WINDOW_HEIGHT);
			params->z.re = 0;
			params->z.im = 0;
			params->c.re = p_re;
			params->c.im = p_im;
			
			// printf("\nINTERATIONS: %d", interations(params));
			// put_color(params, x, y, interations(params));
			my_mlx_pixel_put(params, x, y, color(params, interations(params)));
				// put_color(vars);
			// printf("\nP_RE: %f", p_re);
			// printf("\nP_IM: %f", p_im);
			// printf("\n");
		}
		p_re = params->min_re;
	}
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img, 0, 0);
}

void	render_fractal(t_fractol *params)
{
	mlx_clear_window(params->mlx, params->mlx_win);
	params->img = mlx_new_image(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	params->buff = mlx_get_data_addr(params->img, &params->bits_per_pixel,
			&params->line_size, &params->endian);
	mandelbrot(params);
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
