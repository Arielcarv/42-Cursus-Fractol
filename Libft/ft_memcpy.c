/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:51:46 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/27 17:46:21 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t char_number)
{
	char	*temp_dest_pointer;
	char	*temp_src_pointer;

	if (!dest)
		return (NULL);
	temp_dest_pointer = (char *) dest;
	temp_src_pointer = (char *) src;
	if (temp_dest_pointer != 0)
		while (char_number-- > 0)
			*(temp_dest_pointer++) = *(temp_src_pointer++);
	return (dest);
}
