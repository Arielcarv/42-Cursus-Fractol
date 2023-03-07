/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:31:50 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/26 17:18:20 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while ((index < size - 1) && (*(src + index) != '\0'))
		{
			*(dest + index) = *(src + index);
			index++;
		}
		*(dest + index) = '\0';
	}
	return (ft_strlen(src));
}
