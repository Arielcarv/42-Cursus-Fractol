/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:38:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/10/11 20:17:27 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int caracter);

int main(void)
{
	for (int ascii_item = 0; ascii_item <= 127; ascii_item++)
	{
		if (ft_isascii(ascii_item) != isascii(ascii_item))
		{
			printf("ASCII ITEM %c -> My=%d - Original=%d\n", ascii_item, ft_isascii(ascii_item), isascii(ascii_item));
			return(1);
		}
	}
	printf("ft_isascii - OK\n");
	return (0);
}
