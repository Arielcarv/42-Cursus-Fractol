/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:37:26 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/08 16:02:59 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_printf(char *str)
{
	int	index;

	if (!str)
	{
		ft_putstr_printf("(null)");
		return (6);
	}
	index = 0;
	while (str[index])
		ft_putchar_printf(str[index++]);
	return (index);
}
