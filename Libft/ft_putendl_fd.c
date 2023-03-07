/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:06:14 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/19 18:09:10 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int file_descriptor)
{
	ft_putstr_fd(str, file_descriptor);
	ft_putchar_fd('\n', file_descriptor);
}
