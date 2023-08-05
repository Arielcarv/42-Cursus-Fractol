/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:23:29 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/05 16:06:34 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *params)
{
	mlx_loop_end(params->mlx);
	mlx_destroy_display(params->mlx);
	free(params->mlx);
	exit(0);
	return (0);
}

int	key_events_handler(int keysym, t_fractol *params)
{
	if (keysym == KEY_ESC)
	{
		close_window(params->mlx);
	}
	else
	{
		printf("KEYSYM:%d\n", keysym);
		return (0);
	}
	return (1);
}

int	mouse_events_handler(int keysym, t_fractol *params)
{
	printf("MOUSE KEYSYM: %d\n", keysym);
	return (0);
}
