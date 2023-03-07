/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:51:15 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 22:50:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int caracter, size_t length)
{
	unsigned char	*string;

	if (!str)
		return (0);
	string = str;
	while (length > 0)
	{
		*string = (unsigned char)caracter;
		string++;
		length--;
	}
	return (str);
}
