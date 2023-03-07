/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:20:06 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 17:27:39 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t char_number)
{
	char	*temp_dest;
	char	*temp_src;

	if (!src || !char_number)
		return (dest);
	temp_dest = (char *) dest;
	temp_src = (char *) src;
	if (temp_dest < temp_src)
	{
		ft_memcpy(temp_dest, temp_src, char_number);
		return (dest);
	}
	while (char_number-- > 0)
		*(temp_dest + char_number) = *(temp_src + char_number);
	return (dest);
}
