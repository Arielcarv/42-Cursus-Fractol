/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:49:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/20 15:36:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/bsd.h>
#include <bsd/string.h>

char	*ft_strrchr(char const *str, int caracter);

	int main(void)
{
	char	src1[] = "Something";
	printf("SRC: %s - DEST: %s\n", src1, ft_strrchr(src1, '\0'));

	char	src2[] = "Something";
	printf("SRC: %s - DEST: %s\n", src2, strrchr(src2, '\0'));

	char	src3[8] = "Abacate";
	printf("SRC: %s - DEST: %s\n", src3, ft_strrchr(src3, 't' + 256));

	char	src4[8] = "Abacate";
	printf("SRC: %s - DEST: %s\n", src4, strrchr(src4, 't' + 256));

	return (0);
}
