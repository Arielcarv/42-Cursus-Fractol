/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:21:20 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/17 17:03:24 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_julia(t_fractol *params)
{
	params->min_re = -1.5 + params->key_x;
	params->max_re = 1.5 + params->key_x;
	params->min_im = -1.5 + params->key_y;
	params->max_im = 1.5 + params->key_y;
	params->p_re = params->min_re;
	params->p_im = params->max_im;
}

void	julia(t_fractol *params)
{
	int	x;
	int	y;

	init_julia(params);
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
			params->z.re = params->p_re;
			params->z.im = params->p_im;
			my_mlx_pixel_put(params, x, y,
				rotate_color(params, interations(params)));
		}
		params->p_re = params->min_re;
	}
}
