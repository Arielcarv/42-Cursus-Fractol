/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:19:35 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/16 20:23:40 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_params(t_fractol *params)
{
	params->mlx = NULL;
	params->mlx_win = NULL;
	params->img = NULL;
	params->buff = NULL;
	params->bits_per_pixel = 0;
	params->line_size = 0;
	params->endian = 0;
	params->zoom = 1.0;
	params->min_re = -2.0;
	params->max_im = 2.0;
	params->key_x = 0.0;
	params->key_y = 0.0;
}

void	open_window(t_fractol *params)
{
	params->mlx = mlx_init();
	params->mlx_win = mlx_new_window(
			params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol!");
}
