/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:19:45 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/17 12:20:49 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_fractol *params)
{
	params->min_re = -2.0 + params->key_x;
	params->max_re = 2.0 + params->key_x;
	params->min_im = -2.0 + params->key_y;
	params->max_im = 2.0 + params->key_y;
	params->p_re = params->min_re;
	params->p_im = params->max_im;
}

void	mandelbrot(t_fractol *params)
{
	int	x;
	int	y;

	init_mandelbrot(params);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		params->p_im -= ((fabs(params->max_im) + fabs(params->min_im))
				/ (WINDOW_HEIGHT / params->zoom));
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			params->p_re += ((fabs(params->max_re) + fabs(params->min_re))
					/ (WINDOW_HEIGHT / params->zoom));
			params->z.re = 0;
			params->z.im = 0;
			params->c.re = params->p_re;
			params->c.im = params->p_im;
			my_mlx_pixel_put(params, x, y,
				rotate_color(params, iterations(params)));
		}
		params->p_re = params->min_re;
	}
}
