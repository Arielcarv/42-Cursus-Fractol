/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:23:54 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 23:15:38 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*function)(unsigned int, char*))
{
	int	index;

	index = 0;
	if (!str || !function)
		return ;
	while (*(str + index))
	{
		function(index, (str + index));
		index++;
	}
}
