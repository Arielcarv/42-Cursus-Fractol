/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:23:29 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/17 11:48:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *params)
{
	mlx_loop_end(params->mlx);
	// mlx_destroy_display(params->mlx);
	// if (params->mlx_win)
	// {
	// 	ft_bzero(params->buff, WINDOW_WIDTH * WINDOW_HEIGHT * (params->bits_per_pixel / 8));
	// 	mlx_destroy_image(params->mlx, params->img);
	// 	free(params);
	// 	free(params->mlx);
	// }
	mlx_clear_window(params->mlx, params->mlx_win);
	mlx_destroy_window(params->mlx, params->mlx_win);
	exit(0);
	// return (0);
}

int	key_events_handler(int keysym, t_fractol *params)
{
	if (keysym == KEY_ESC)
		close_window(params->mlx);
	else if (keysym == KEY_DOWN)
		params->key_y -= 0.2 * params->zoom;
	else if (keysym == KEY_UP)
		params->key_y += 0.2 * params->zoom;
	else if (keysym == KEY_RIGHT)
		params->key_x += 0.2 * params->zoom;
	else if (keysym == KEY_LEFT)
		params->key_x -= 0.2 * params->zoom;
	else if (keysym == KEY_ONE)
	{
		if (params->color > 0xFE0000)
			params->color = params->color >> 16;
		else
			params->color = params->color << 4;
	}
	render_fractal(params);
	return (0);
}

int	mouse_events_handler(int keysym, int x, int y, t_fractol *params)
{
	(void)x;
	(void)y;
	if (keysym == MOUSE_SCROLL_UP)
	{
		params->zoom -= 0.1 * params->zoom;
		params->key_y -= 0.05;
	}
	if (keysym == MOUSE_SCROLL_DOWN)
	{
		params->zoom += 0.1 * params->zoom;
		params->key_x += 0.2;
	}
	render_fractal(params);
	return (0);
}

void	set_hooks(t_fractol *params)
{
	mlx_hook(params->mlx_win, CLOSE_BUTTON, 0, close_window, params);
	mlx_key_hook(params->mlx_win, key_events_handler, params);
	mlx_mouse_hook(params->mlx_win, mouse_events_handler, params);
}
