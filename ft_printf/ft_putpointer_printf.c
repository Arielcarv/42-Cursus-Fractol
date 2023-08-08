/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:44:37 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/20 19:06:42 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_findhex_pointer_magnitude(unsigned long long number)
{
	int	magnitude;

	magnitude = 1;
	while (number >= 16)
	{
		number = number / 16;
		magnitude++;
	}
	return (magnitude);
}

static int	ft_puthex_pointer(unsigned long long number)
{
	int		magnitude;
	char	*base_hex;

	base_hex = "0123456789abcdef";
	magnitude = ft_findhex_pointer_magnitude(number);
	if (number >= 16)
	{
		ft_puthex_pointer(number / 16);
		ft_putchar_printf(base_hex[number % 16]);
		return (magnitude);
	}
	ft_putchar_printf(base_hex[number]);
	return (magnitude);
}

int	ft_putpointer(unsigned long long number)
{
	int	printed;

	printed = 0;
	printed += ft_putstr_printf("0x");
	printed += ft_puthex_pointer(number);
	return (printed);
}
