/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:09:25 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 18:33:23 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t char_number)
{
	const unsigned char	*temp_str1;
	const unsigned char	*temp_str2;

	temp_str1 = str1;
	temp_str2 = str2;
	while (char_number > 0)
	{
		if (*temp_str1 != *temp_str2)
			return (*temp_str1 - *temp_str2);
		temp_str1++;
		temp_str2++;
		char_number--;
	}
	return (0);
}
