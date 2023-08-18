/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:13:58 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/18 18:21:58 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	interations(t_fractol *params)
{
	double	z_re_temp;

	params->interations = 0;
	while (params->interations < 255)
	{
		z_re_temp = params->z.re;
		params->z.re = ((params->z.re * params->z.re)
				- (params->z.im * params->z.im)) + params->c.re;
		params->z.im = (2 * z_re_temp * params->z.im) + params->c.im;
		if (((params->z.re * params->z.re) + (params->z.im * params->z.im)) > 4)
			break ;
		params->interations++;
	}
	return (params->interations);
}

static int	atod_check(char *s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (s[i] != 0)
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[0] == '-')
		{
			if (s[i] == '-')
				sign = -1;
			i++;
		}
		else
			return (2);
	}
	return (sign);
}

double	ft_atod(char *s)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;
	double	div;

	sign = atod_check(s);
	if (sign == 2)
		return (-5);
	result = ft_atoi(s);
	i = 0;
	while (s[i] != 0 && s[i] != '.')
		i++;
	decimal = 0.0;
	div = 0;
	if (s[i++] == '.')
	{
		decimal = ft_atoi(&s[i]);
		while (s[i++] != 0)
			div++;
	}
	while (div-- > 0)
		decimal /= 10;
	return (result + (sign * decimal));
}


void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dest;

	dest = fractol->buff + (y * fractol->line_size + x
			* (fractol->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	rotate_color(t_fractol *params, int i)
{
	int	n;

	if (params->interations == 255)
		return (0);
	n = 3;
	while (--n >= 1)
		i = (i * params->color) / 64;
	return (i);
}
