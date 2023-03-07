/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:32:53 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 19:08:52 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	size_t	length;
	char	*copy_str;

	length = ft_strlen(str) + 1;
	copy_str = malloc(length);
	if (copy_str == NULL)
		return (NULL);
	ft_memcpy(copy_str, str, length);
	return (copy_str);
}
