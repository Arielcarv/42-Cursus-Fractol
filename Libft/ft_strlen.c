/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:45:32 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/31 20:50:13 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}
