/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:28:53 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 18:56:21 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_add_sign(char *dest, int negative)
{
	if (negative)
	{
		dest[0] = '-';
		return (1);
	}
	return (0);
}

static int	ft_find_size(int number, int negative)
{
	int	size;
	int	magnitude;

	magnitude = 1;
	while (number >= 10)
	{
		magnitude = magnitude * 10;
		number = number / 10;
	}
	size = 0;
	while (magnitude >= 1)
	{
		magnitude = magnitude / 10;
		size++;
	}
	if (negative)
		return (size + 1);
	return (size);
}

static int	ft_power(int base, unsigned int exponential )
{
	int	temp;

	if (exponential == 0)
		return (1);
	temp = ft_power(base, exponential / 2);
	if (exponential % 2 == 0)
		return (temp * temp);
	return (base * temp * temp);
}

char	*ft_itoa(int number)
{
	char	*dest;
	int		negative;
	int		str_size;
	int		index;

	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	if (number < 0)
		negative = 1;
	if (number < 0)
		number = -number;
	str_size = ft_find_size(number, negative);
	dest = malloc(sizeof(char) * str_size + 1);
	if (!dest)
		return (0);
	index = ft_add_sign(dest, negative);
	while (index < str_size)
	{
		*(dest + index) = (number / ft_power(10, (str_size - index - 1))) + '0';
		number = number % ft_power(10, (str_size - index - 1));
		index++;
	}
	*(dest + str_size) = '\0';
	return (dest);
}
