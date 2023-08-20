/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:47:21 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/13 22:51:19 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_find_magnitude(int number)
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

static int	ft_bigger(int number)
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

int	ft_putnbr_printf(int number)
{
	int	printed;

	printed = 0;
	if (number == -2147483648)
	{
		ft_putstr_printf("-2147483648");
		return (11);
	}
	if (number >= -2147483647 && number < 0)
	{
		ft_putchar_printf('-');
		number = number * (-1);
		printed++;
	}
	if (number >= 0 && number < 10)
		return (printed + ft_putchar_printf((number % 10) + '0'));
	printed += ft_bigger(number);
	return (printed);
}
