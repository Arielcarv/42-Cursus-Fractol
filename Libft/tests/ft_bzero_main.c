/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:37:03 by arcarval          #+#    #+#             */
/*   Updated: 2022/12/03 14:36:16 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *str, size_t number);

int	equalString(char *str1, char *str2, int size)
{
	for (int i=0; i < size; i++)
	{
		if (str1[i] != str2[i])
			return (0);
		// if (str1[i] == '\0')
		// 	printf("\\0");
	}
	return (1);
}

void	ft_check(char *str1, char *str2, int size)
{
	if (equalString(str1, str2, size))
	{
		printf("ft_bzero - OK\n");
		return ;
	}
	printf("ft_bzero - KO\n");
}

int	main(void)
{
	char	str1[40] = "rapadura e doce mas nao e mole nao.";
	char	str2[40] = "rapadura e doce mas nao e mole nao.";
	char	str3[40] = "Uma frase qualquer.";
	char	str4[40] = "Uma frase qualquer.";

	// memset(str1, 'A', 10);
	// memset(str2, 'A', 10);
	// memset(str3, 'A', 10);
	ft_bzero(str1, 8);
	bzero(str2, 8);
	ft_check(str1, str2, 40);

	ft_bzero(str3, 8);
	bzero(str4, 8);
	ft_check(str3, str4, 40);
	return (0);
}
