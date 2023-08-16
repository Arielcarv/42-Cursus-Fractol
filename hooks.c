/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:23:29 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/16 20:33:24 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *params)
{
	// mlx_loop_end(params->mlx);
	// mlx_destroy_display(params->mlx);
	// if (params->mlx_win)
	// {
	// 	// ft_bzero(params->buff, WINDOW_WIDTH * WINDOW_HEIGHT * (params->bits_per_pixel / 8));
	// 	mlx_destroy_image(params->mlx, params->img);
	// 	free(params);
	// }
	mlx_destroy_window(params->mlx, params->mlx_win);
	exit(0);
	return (0);
}

int	key_events_handler(int keysym, t_fractol *params)
{
	if (keysym == KEY_ESC)
	{
		close_window(params->mlx);
		return (0);
	}
	else
	{
		printf("KEYSYM:%d\n", keysym);
		return (0);
	}
	mlx_destroy_image(params->mlx, params->img);
	render_fractal(params);
	return (0);
}

int	mouse_events_handler(int keysym, int x, int y, t_fractol *params)
{
	(void)x;
	(void)y;
	printf("\nMOUSE ZOOM [MOUSE1]: %f", params->zoom);
	if (keysym == MOUSE_SCROLL_UP)
		params->zoom += 0.1;
		params->key_x += 0.1;
	if (keysym == MOUSE_SCROLL_DOWN)
		params->zoom -= 0.1;
		params->key_y -= 0.1;
	// mlx_destroy_display(params->mlx);
	// free(params->mlx);
	// render_fractal(params);
	mlx_clear_window(params->mlx, params->mlx_win);
	render_fractal(params);
	// printf("MOUSE KEYSYM: %d\n", keysym);
	printf("\nMOUSE ZOOM [MOUSE2]: %f", params->zoom);
	return (0);
}

void	set_hooks(t_fractol *params)
{
	mlx_hook(params->mlx_win, CLOSE_BUTTON, 0, close_window, params);
	mlx_key_hook(params->mlx_win, key_events_handler, params);
	mlx_mouse_hook(params->mlx_win, mouse_events_handler, params);
}
