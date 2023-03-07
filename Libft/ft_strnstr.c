/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:52:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 18:38:51 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t length)
{
	size_t	needle_len;

	if (!haystack || !needle)
		return (0);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack && needle_len <= length)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		length--;
	}
	return (0);
}
