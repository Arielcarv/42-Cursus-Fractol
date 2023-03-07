/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:31:30 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/28 23:40:53 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../Libft/libft.h"

t_list	*ft_lstnew(void *content);

int	main(void)
{
	t_list		*another_new_node;
	long int	as_number;

	another_new_node = ft_lstnew((void *)10);
	as_number = (long int) another_new_node->content;
	printf("%ld\n", as_number);
	as_number = (long int) ft_lstnew((void *)11)->content;
	printf("%ld\n", as_number);
	printf("%ld\n", (long int) ft_lstnew((void *)12)->content);
	return (0);
}
