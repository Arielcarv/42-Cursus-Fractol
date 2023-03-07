/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:02:58 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/22 13:44:58 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *str1, char const *str2, size_t char_number)
{
	while (*str1 && (*str1 == *str2) && (char_number > 0))
	{
		str1++;
		str2++;
		char_number--;
	}
	if (*str1 == *str2 || char_number == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
