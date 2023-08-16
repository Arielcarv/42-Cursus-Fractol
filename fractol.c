/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/16 20:32:57 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>


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
	int		x;
	int		y;
	double	p_re;
	double	p_im;

	// p_re = params->min_re;
	p_re = params->min_re + params->key_x;
	// p_im = params->max_im;
	p_im = params->max_im + params->key_y;
	printf("\nP_IM: %f", p_im);
	printf("\nP_RE: %f", p_re);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		p_im -= ((fabs(params->max_im) + fabs(params->max_im)) / (WINDOW_HEIGHT / params->zoom));
		// p_im -= params->key_y + ((fabs(params->max_im) + fabs(params->max_im)) / (WINDOW_HEIGHT / params->zoom));
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			// printf("\nRESULT: %f", ((fabs(params->min_re) + fabs(params->min_re)) / WINDOW_HEIGHT));
			p_re += ((fabs(params->min_re) + fabs(params->min_re)) / (WINDOW_HEIGHT / params->zoom));
			// p_re += params->key_x + ((fabs(params->min_re) + fabs(params->min_re)) / (WINDOW_HEIGHT / params->zoom));
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
}

void	render_fractal(t_fractol *params)
{
	// printf("MOUSE ZOOM1: %f\n", params->zoom);
	// mlx_clear_window(params->mlx, params->mlx_win);
	params->img = mlx_new_image(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	params->buff = mlx_get_data_addr(params->img, &params->bits_per_pixel,
			&params->line_size, &params->endian);
	// printf("MOUSE ZOOM2: %f\n", params->zoom);
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
	set_hooks(&params);
	render_fractal(&params);
	mlx_loop(params.mlx);
	return (0);
}
