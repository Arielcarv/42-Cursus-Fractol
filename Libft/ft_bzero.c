/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:49:11 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 23:07:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t number)
{
	char	*pointer;
	int		index;

	pointer = str;
	index = 0;
	while (number-- > 0)
		pointer[index++] = '\0';
}
