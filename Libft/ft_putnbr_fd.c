/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:47:21 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 23:13:10 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_bigger(int number, int file_descriptor)
{
	int	magnitude;

	magnitude = ft_find_magnitude(number);
	while (magnitude > 0)
	{
		ft_putchar_fd((number / magnitude) + '0', file_descriptor);
		number = (number % magnitude);
		magnitude = magnitude / 10;
	}
}

void	ft_putnbr_fd(int number, int file_descriptor)
{
	if (number == -2147483648)
	{
		write(file_descriptor, "-2147483648", 11);
		return ;
	}
	if (number >= -2147483647 && number < 0)
	{
		ft_putchar_fd('-', file_descriptor);
		number = number * (-1);
	}
	if (number >= 0 && number < 10)
	{
		ft_putchar_fd((number % 10) + '0', file_descriptor);
		return ;
	}
	ft_bigger(number, file_descriptor);
}
