/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:18:55 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/08 18:47:21 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef __APPLE__
#  include "libraries/minilibx-macos/mlx.h"
# else
#  include "libraries/minilibx-linux/mlx.h"
# endif

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480

// KEYBOARD KEYS
# define CLOSE_BUTTON 17
# define KEY_SPACE 32
# define KEY_ZERO 48
# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_THREE 51
# define KEY_FOUR 52
# define KEY_FIVE 53
# define KEY_PLUS 43
# define KEY_MINUS 45
# define KEY_A 97
# define KEY_B 98
# define KEY_C 99
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define MOUSE_LEFT 1
# define MOUSE_MIDDLE 2
# define MOUSE_RIGHT 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_fractol {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*buff;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_fractol;

void	initialize_params(t_fractol *params);
void	open_window(t_fractol *params);
int		close_window(t_fractol *params);
int		key_events_handler(int keysym, t_fractol *params);
int		mouse_events_handler(int keysym, t_fractol *params);

#endif