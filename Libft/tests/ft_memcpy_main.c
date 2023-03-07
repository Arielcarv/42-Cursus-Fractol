/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:51:15 by arcarval          #+#    #+#             */
/*   Updated: 2022/12/03 15:01:52 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t char_number);
size_t	ft_strlen(char const *str);

void	printArray(char arr[], int n)
{
	for (int i=0; i<n; i++)
		printf("%c", arr[i]);
}

int	equalString(char arr1[], char arr2[], int size)
{
	for (int i=0; i < size; i++)
	{
		// printf("%d ", arr1[i] == arr2[i]);
		if (arr1[i] != arr2[i])
			return (0);
	}
	return (1);
}

void	ft_check(char *str1, char *str2, int size)
{
	if (equalString(str1, str2, size))
	{
		printf("ft_memcpy - OK\n");
		return ;
	}
	printf("ft_memcpy - KO\n");
}

int	main(void)
{
	char	str1[] = "rapadura e doce mas nao e mole nao.";
	int		n1 = ft_strlen(str1);
	char	str2[n1];
	char	str3[n1];
	char	str4[] = "Uma frase qualquer.";
	int		n2 = ft_strlen(str4);
	char	str5[n2];
	char	str6[n2];

	memcpy(str2, str1, n1 + 1);
	ft_memcpy(str3, str1, n1 + 1);
	// printArray(str2, n1);
	// printArray(str3, n1);
	ft_check(str2, str3, n1);

	memcpy(str5, str4, n2 + 1);
	ft_memcpy(str6, str4, n2 + 1);
	ft_check(str5, str6, n2);
	// printArray(str5, n2);
	// printArray(str6, n2);

	return (0);
}
