/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:11:00 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 19:23:05 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dest_length(int start, int max_length, int src_length)
{
	int	dest_length;

	if (start >= src_length)
		return (0);
	if (max_length > src_length)
		return (src_length + 1);
	dest_length = src_length - start;
	if (max_length > dest_length)
		return (dest_length + 1);
	return (max_length + 1);
}

char	*ft_substr(char const *src, unsigned int start, size_t max_length)
{
	int		dest_length;
	char	*dest;

	if (!src)
		return (0);
	dest_length = ft_dest_length(start, max_length, ft_strlen(src));
	if (dest_length == 0)
		return (ft_strdup(""));
	dest = (char *) malloc(dest_length * sizeof(char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, src + start, dest_length);
	return (dest);
}
