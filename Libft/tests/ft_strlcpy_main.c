/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:49:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/12/03 12:20:03 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/bsd.h>
#include <bsd/string.h>

size_t	ft_strlcpy(char *dest, char const *src, size_t size);

void	printArray(char *arr)
{
	while (*arr)
	{
		printf("%c ", *arr);
		arr++;
	}
}

int	equalString(char *arr1, char *arr2)
{
	while (*arr1 && *arr2)
	{
		// printf("%d ", arr1[i] == arr2[i]);
		if (*arr1 != *arr2)
			return (0);
		arr1++;
		arr2++;
	}
	return (1);
}

int	main(void)
{
	char	src1[] = "Something";
	char	dest1[10];
	// printf("SRC: %s - DEST: %s - %lu\n", src1, dest1, ft_strlcpy(dest1, src1, 10));

	char	src2[] = "Something";
	char	dest2[10];
	// printf("SRC: %s - DEST: %s - %lu\n", src2, dest2, strlcpy(dest2, src2, 10));
	ft_strlcpy(dest1, src1, 10);
	strlcpy(dest2, src2, 10);
	// printArray(dest1);
	// printArray(dest2);
	if (equalString(dest1, dest2))
		printf("ft_strlcpy - OK \n");
	else
		printf("ft_strlcpy - KO \n");

	char	src3[8] = "Abacate";
	char	dest3[10] = "Manga";
	// printf("SRC: %s - DEST: %s - %lu\n", src3, dest3, ft_strlcpy(dest3, src3, 0));

	char	src4[8] = "Abacate";
	char	dest4[10] = "Manga";
	// printf("SRC: %s - DEST: %s - %lu\n", src4, dest4, strlcpy(dest4, src4, 0));
	ft_strlcpy(dest3, src3, 10);
	strlcpy(dest4, src4, 10);
	if (equalString(dest3, dest4))
		printf("ft_strlcpy - OK \n");
	else
		printf("ft_strlcpy - KO \n");

	return (0);
}
