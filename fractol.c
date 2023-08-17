/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:00:54 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/17 12:22:29 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractol *params)
{
	mlx_clear_window(params->mlx, params->mlx_win);
	params->img = mlx_new_image(params->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	params->buff = mlx_get_data_addr(params->img, &params->bits_per_pixel,
			&params->line_size, &params->endian);
	if (params->validation == 1)
		mandelbrot(params);
	// if (params->validation == 2)
		// julia(params);
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	params;

	if (validate_input(argc, argv, &params) == 1)
		return (0);
	initialize_params(&params);
	open_window(&params);
	render_fractal(&params);
	set_hooks(&params);
	mlx_loop(params.mlx);
	return (0);
}
