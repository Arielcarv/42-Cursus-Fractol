/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:18:55 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/18 16:27:00 by arcarval         ###   ########.fr       */
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
# include <math.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

// KEYBOARD KEYS
# define CLOSE_BUTTON 17
# define KEY_ONE 49
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_complex {
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractol {
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*buff;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	double			p_re;
	double			p_im;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			key_x;
	double			key_y;
	t_complex		z;
	t_complex		c;
	int				iterations;
	double			zoom;
	unsigned int	color;
	int				validation;
}			t_fractol;

void	initialize_params(t_fractol *params);
void	open_window(t_fractol *params);
void	set_hooks(t_fractol *params);
int		iterations(t_fractol *params);
void	render_fractal(t_fractol *params);
void	mandelbrot(t_fractol *params);
void	julia(t_fractol *params);
void	burning_ship(t_fractol *params);
void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
int		rotate_color(t_fractol *params, int i);
int		validate_input(int argc, char **argv, t_fractol *params);
double	ft_atod(char *s);

#endif