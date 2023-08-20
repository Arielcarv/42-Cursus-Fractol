/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:47:21 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/13 22:53:00 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_find_magnitude(unsigned int number)
{
	int	magnitude;

	magnitude = 1;
	while (number >= 10)
	{
		magnitude = magnitude * 10;
		number = number / 10;
	}
	return (magnitude);
}

static int	ft_bigger(unsigned int number)
{
	int	magnitude;
	int	printed;

	printed = 0;
	magnitude = ft_find_magnitude(number);
	while (magnitude > 0)
	{
		ft_putchar_printf((number / magnitude) + '0');
		number = (number % magnitude);
		magnitude = magnitude / 10;
		printed++;
	}
	return (printed);
}

int	ft_putnbr_unsigned_fd(unsigned int number)
{
	if (number > 0 && number < 10)
		return (ft_putchar_printf((number % 10) + '0'));
	return (ft_bigger(number));
}
