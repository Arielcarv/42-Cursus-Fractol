/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:26:39 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/20 15:36:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int caracter)
{
	int		length;
	char	temp_caracter;

	length = ft_strlen(str);
	if (caracter == '\0')
		return ((char *)(str + length));
	temp_caracter = caracter;
	while (length > 0 && *(str + length) != temp_caracter)
		length--;
	if (*(str + length) == temp_caracter)
		return ((char *)str + length);
	return (0);
}
