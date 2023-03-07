/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:45:14 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/17 00:55:24 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char	i1[] = "0";
	char	i2[] = " 123:<456";
	char	i3[] = " -1234ab567";
	char	i4[] = "-2147483648";
	char	i5[] = "2147483647";
	char	i6[] = "+123";
	char	i7[] = "++123";
	char	i8[] = "2147483647";
	char	i9[] = "\t\n\v\f\r123 \n";
	char	i10[] = "\t \ra123 ";

	printf("%d\n", ft_atoi(i1));
	printf("%d\n", ft_atoi(i2));
	printf("%d\n", ft_atoi(i3));
	printf("%d\n", ft_atoi(i4));
	printf("%d\n", ft_atoi(i5));
	printf("%d\n", ft_atoi(i6));
	printf("%d\n", ft_atoi(i7));
	printf("%d\n", ft_atoi(i8));
	printf("%d\n", ft_atoi(i9));
	printf("%d\n", ft_atoi(i10));
}
