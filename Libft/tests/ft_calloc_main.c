/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:51:15 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/17 22:07:45 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	n;
	int	*pData;

	printf ("Amount of numbers to be entered: ");
	scanf ("%d", &i);
	pData = (int*) ft_calloc(i, 0);
	if (pData==NULL)
		exit(1);
	for (n=0; n<i; n++)
	{
		printf("Enter number #%d: ", n+1);
		scanf("%d", &pData[n]);
	}
	printf ("You have entered: ");
	for (n=0;n<i;n++) 
		printf("%d ", pData[n]);
	free(pData);
	return (0);
}
