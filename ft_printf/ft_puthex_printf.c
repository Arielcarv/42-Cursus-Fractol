/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:46:13 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/15 13:13:26 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(long int number, char *base_hex)
{
	int	magnitude;

	magnitude = 0;
	if (number < 0)
		number = 0xffffffff - ~number;
	if (number >= 16)
	{
		magnitude += ft_puthex(number / 16, base_hex);
		magnitude += ft_putchar_printf(base_hex[number % 16]);
		return (magnitude);
	}
	magnitude += ft_putchar_printf(base_hex[number]);
	return (magnitude);
}
