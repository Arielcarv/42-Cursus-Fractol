/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:40:35 by arcarval          #+#    #+#             */
/*   Updated: 2022/10/13 19:18:39 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int caracter);

int	main(void)
{
	for (int ascii_item = 0; ascii_item < 128; ascii_item++)
	{
		if (ft_toupper(ascii_item) != toupper(ascii_item))
		{
			printf("ASCII ITEM %c -> My=%d - Original=%d\n", ascii_item, ft_toupper(ascii_item), toupper(ascii_item));
			return(1);
		}
	}
	printf("ft_toupper - OK\n");
	return (0);
}
