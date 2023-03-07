/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:33:48 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/27 16:48:04 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		str1_length;
	int		str2_length;
	char	*dest;

	if (!str1 || ! str2)
		return (0);
	str1_length = ft_strlen(str1);
	str2_length = ft_strlen(str2);
	dest = malloc((str1_length + str2_length + 1) * sizeof(char));
	if (!dest)
		return (0);
	ft_memcpy(dest, str1, str1_length);
	ft_memcpy(dest + str1_length, str2, str2_length);
	*(dest + str1_length + str2_length) = '\0';
	return (dest);
}
