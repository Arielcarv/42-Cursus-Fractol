/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:38:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/20 15:36:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char const *str);

int main(void)
{
	char	str1[] = "A person that is crazy or behaving in idiotic ways";
	char	str2[] = "To be enraged and show it.";
	char	str3[] = "To tolerate or endure through the unexpected mishappenings you may encounter from time to time.";

	if (ft_strlen(str1) != strlen(str1) || ft_strlen(str2) != strlen(str2) || ft_strlen(str3) != strlen(str3))
	{
		printf("ASCII ITEM %s -> My=%ld - Original=%ld\n", str1, ft_strlen(str1), strlen(str1));
		printf("ASCII ITEM %s -> My=%ld - Original=%ld\n", str2, ft_strlen(str2), strlen(str2));
		printf("ASCII ITEM %s -> My=%ld - Original=%ld\n", str3, ft_strlen(str3), strlen(str3));
		return(1);
	}
	printf("ft_strlen - OK\n");
	return (0);
}
