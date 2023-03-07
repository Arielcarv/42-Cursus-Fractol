/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:41:56 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/21 22:06:36 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strtrim(char const *str, char const *set);

int	main(void)
{
	char *str1 = "lorem \n ipsum \t dolor \n sit \t amet";
	char *set1 = " ";
	printf("|%s|\n", ft_strtrim(str1, set1));
	char *str2 = "lorem ipsum dolor sit amet";
	char *set2 = "te";
	printf("|%s|\n", ft_strtrim(str2, set2));
	char *str3 = " lorem ipsum dolor sit amet";
	char *set3 = "l ";
	printf("|%s|\n", ft_strtrim(str3, set3));
	char *str4 = "lorem ipsum dolor sit amet";
	char *set4 = " ";
	printf("|%s|\n", ft_strtrim(str4, set4));
	char *str5 = "          ";
	char *set5 = "tel";
	printf("|%s|\n", ft_strtrim(str5, set5));
	char *str6 = "   xxxtripouille   xxx";
	char *set6 = " x";
	printf("|%s|\n", ft_strtrim(str6, set6));
	return (0);
}
