/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:41:56 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 19:36:24 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	int	start;
	int	end;

	start = 0;
	if (!str || !set)
		return (0);
	while (*(str + start) && ft_strchr(set, *(str + start)))
		start++;
	end = ft_strlen(str);
	while (end && ft_strchr(set, *(str + end)))
		end--;
	return (ft_substr(str, start, (end - start) + 1));
}
