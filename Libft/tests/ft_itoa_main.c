/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:44:01 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/20 22:40:06 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_itoa(int number);

int	main(void)
{
	printf("%s\n", ft_itoa(9));
	printf("%s\n", ft_itoa(-9));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-100));
	printf("%s\n", ft_itoa(200));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}
