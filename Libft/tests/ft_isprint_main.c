/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:38:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/10/12 20:21:27 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int caracter);

int main(void)
{
	for (int ascii_item = 0; ascii_item < 128; ascii_item++)
	{
		if ((ft_isprint(ascii_item) == 0 && isprint(ascii_item) != 0) || (ft_isprint(ascii_item) != 0 && isprint(ascii_item) == 0))
		{
			printf("ASCII ITEM %c -> My=%d - Original=%d\n", ascii_item, ft_isprint(ascii_item), isprint(ascii_item));
			return (1);
		}
	}
	printf("ft_isprint - OK\n");
	return (0);
}
