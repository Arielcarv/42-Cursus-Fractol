/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:18:55 by arcarval          #+#    #+#             */
/*   Updated: 2023/06/12 17:26:22 by arcarval         ###   ########.fr       */
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

#endif