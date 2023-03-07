/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:08:16 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/15 17:03:15 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int caracter, size_t char_number)
{
	size_t	index;
	char	*temp_str;

	index = 0;
	temp_str = (char *) str;
	while (index < char_number)
	{
		if (temp_str[index] == (char) caracter)
			return ((void *) &temp_str[index]);
		index++;
	}
	return (0);
}
