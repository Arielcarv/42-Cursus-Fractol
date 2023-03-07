/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:27:59 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/29 00:48:21 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number_spaces, size_t size)
{
	void	*empty_str;

	empty_str = malloc(number_spaces * size);
	if (empty_str != 0)
	{
		ft_bzero(empty_str, number_spaces * size);
		return (empty_str);
	}
	return (NULL);
}
