/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:21:58 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 23:16:40 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char const *str, int caracter)
{
	char	temp_caracter;
	int		index;

	temp_caracter = caracter;
	index = 0;
	while (*(str + index) && (*(str + index) != temp_caracter))
		index++;
	if (*(str + index) == temp_caracter)
		return ((char *)str + index);
	return (0);
}
