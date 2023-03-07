/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:46:12 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/22 18:11:53 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/bsd.h>
#include <bsd/string.h>

size_t	ft_strlcat(char *dest, char const *src, size_t size);

int	main(void)
{
	char src1[] = "Something";
	char dest1[10];
	printf("SRC: %s - DEST: %s - %lu\n", src1, dest1, ft_strlcat(dest1, src1, 10));

	char src2[] = "Something";
	char dest2[10];
	printf("SRC: %s - DEST: %s - %lu\n", src2, dest2, strlcat(dest2, src2, 10));

	char src3[8] = "Abacate";
	char dest3[10] = "Manga";
	printf("SRC: %s - DEST: %s - %lu\n", src3, dest3, ft_strlcat(dest3, src3, 7));

	char src4[8] = "Abacate";
	char dest4[10] = "Manga";
	printf("SRC: %s - DEST: %s - %lu\n", src4, dest4, strlcat(dest4, src4, 7));

	char src5[8] = "Abacate";
	char dest5[8] = "Abacate";
	printf("SRC: %s - DEST: %s - %lu\n", src5, dest5, ft_strlcat(dest5, src5, '\0'));

	char src6[8] = "Abacate";
	char dest6[8] = "Abacate";
	printf("SRC: %s - DEST: %s - %lu\n", src6, dest6, strlcat(dest6, src6, '\0'));

	return (0);
}
