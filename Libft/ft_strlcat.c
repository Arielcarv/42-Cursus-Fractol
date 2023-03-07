/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:05:18 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/27 16:35:00 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	index;

	if (!src || !dest)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size < dest_len)
		return (size + src_len);
	index = 0;
	while (*(src + index) && (dest_len + index + 1 < size))
	{
		*(dest + dest_len + index) = *(src + index);
		index++;
	}
	*(dest + dest_len + index) = '\0';
	return (dest_len + src_len);
}
