/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:51:15 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 16:38:10 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *str, int caracter, size_t n);

void	printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
}

int	equalString(int arr1[], int arr2[], int n)
{
	for (int i=0; i<n; i++)
	{
		// printf("%d ", arr1[i] == arr2[i]);
		if (arr1[i] != arr2[i])
			return (0);
	}
	return (1);
}

int	main(void)
{
	int	n = 10;
	int	arr1[n];
	int	arr2[n];
	// int	arr3[] = NULL;
	// int	arr4[] = NULL;

	memset(arr1, 1, n * sizeof(int));
	// printf("Array after original memset()\n-> ");
	// printArray(arr1, n);

	ft_memset(arr2, 1, n * sizeof(int));
	// printf("\nArray after memset()\n-> ");
	// printArray(arr2, n);
	if (equalString(arr1, arr2, n))
		printf("ft_memset - OK ");
	else
		printf("ft_memset - KO ");

	// memset(NULL, 1, 0);
	// printf("Array after original memset()\n-> ");
	// printArray(arr1, n);

	// ft_memset(NULL, 1, 0);
	// printf("\nArray after memset()\n-> ");
	// printArray(arr2, n);
	// equalString(arr3, arr4, n);
	// printf("\n ");

	return (0);
}
