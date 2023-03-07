/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:51:00 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/26 17:14:35 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split(char const *str, char delimiter);

void	ft_print_matrix(char **matrix)
{
	int	row;
	int	column;

	row = 0;
	while (matrix[row][0])
	{
		column = 0;
		while (matrix[row][column])
		{
			if (matrix[row][column])
				printf("%c", matrix[row][column]);
			column++;
		}
		row++;
		printf("\n");
	}
}

int	main(void)
{
	char	*str1 = "  rapadura é doce mais não é mole não.";
	ft_print_matrix(ft_split(str1, ' '));
	
	char	*str2 = "            ";
	ft_print_matrix(ft_split(str2, ' '));
	
	char	*str3 = "    asdasd oiuhrt asdf asasr esdf ";
	ft_print_matrix(ft_split(str3, ' '));
	return (0);
}
