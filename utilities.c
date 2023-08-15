/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:13:58 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/15 19:51:18 by arcarval         ###   ########.fr       */
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