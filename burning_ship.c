/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:17:27 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/20 16:17:27 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterations_bs(t_fractol *params)
{
	double	z_re_temp;

	params->iterations = 0;
	while (params->iterations < 255)
	{
		z_re_temp = params->z.re;
		params->z.re = ((params->z.re * params->z.re)
				- (params->z.im * params->z.im)) + params->c.re;
		params->z.im = (fabs(2 * z_re_temp * params->z.im)) + params->c.im;
		if (((params->z.re * params->z.re) + (params->z.im * params->z.im)) > 4)
			break ;
		params->iterations++;
	}
	return (params->iterations);
}

static void	init_burning_ship(t_fractol *params)
{
	params->min_re = -2.0 + params->key_x;
	params->max_re = 2.0 + params->key_x;
	params->min_im = -2.0 + params->key_y;
	params->max_im = 2.0 + params->key_y;
	params->p_re = params->min_re;
	params->p_im = params->max_im;
}

void	burning_ship(t_fractol *params)
{
	int	x;
	int	y;

	init_burning_ship(params);
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
				rotate_color(params, iterations_bs(params)));
		}
		params->p_re = params->min_re;
	}
}
