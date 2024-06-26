/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:21:05 by arcarval          #+#    #+#             */
/*   Updated: 2023/08/22 16:00:16 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_instructions(void)
{
	ft_printf("\n\033[0;31mExamples of valid arguments:\033[0m"
		"\nmandelbrot"
		"\njulia   0.285   0.01"
		"\njulia  -0.8     0.156"
		"\njulia  -0.835  -0.2321"
		"\njulia  -1.037   0.17"
		"\njulia  -0.52    0.57"
		"\njulia   0.285   0.50"
		"\nburning ship"
		"\n");
	return (1);
}

int	validate_input(int argc, char **argv, t_fractol *params)
{
	if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) == 0))
	{
		params->validation = 1;
	}
	else if (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0)
		&& (ft_atod(argv[2]) >= -2.0 && ft_atod(argv[2]) <= 2.0)
		&& (ft_atod(argv[3]) >= -2.0 && ft_atod(argv[3]) <= 2.0))
	{
		params->validation = 2;
		params->c.re = ft_atod(argv[2]);
		params->c.im = ft_atod(argv[3]);
	}
	else if (argc == 2 && (ft_strncmp(argv[1], "burning ship", 12) == 0))
		params->validation = 3;
	else
		return (print_instructions());
	return (0);
}
