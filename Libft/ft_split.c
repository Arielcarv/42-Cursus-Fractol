/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:14:37 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 18:53:05 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char delimiter)
{
	int	words_quant;

	words_quant = 0;
	while (*str)
	{
		if (*str != delimiter && (*(str + 1) == delimiter || !*(str + 1)))
			words_quant++;
		str++;
	}
	return (words_quant);
}

char	**ft_split(char const *str, char delimiter)
{
	char	**array;
	int		word_num;
	int		index;
	int		start_pos;

	if (!str)
		return (NULL);
	array = ft_calloc(ft_count_words(str, delimiter) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	index = 0;
	word_num = 0;
	while (str[index])
	{
		while (str[index] != 0 && str[index] == delimiter)
			index++;
		start_pos = index;
		while (str[index] != 0 && str[index] != delimiter)
			index++;
		if (word_num < ft_count_words(str, delimiter))
			array[word_num] = ft_substr(str, start_pos, index - start_pos);
		word_num++;
	}
	return (array);
}
