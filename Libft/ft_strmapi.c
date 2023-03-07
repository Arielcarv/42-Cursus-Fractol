/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:40:08 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/27 16:57:11 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*function)(unsigned int, char))
{
	char	*dest_str;
	int		index;

	if (!str)
		return (0);
	dest_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest_str || !str)
		return (0);
	index = 0;
	while (*(str + index))
	{
		*(dest_str + index) = function(index, *(str + index));
		index++;
	}
	*(dest_str + index) = '\0';
	return (dest_str);
}
