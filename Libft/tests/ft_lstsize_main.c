/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:37:51 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/28 23:39:03 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../Libft/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list		*current_node;
	int			size;
	long int	number;

	current_node = lst;
	size = 0;
	number = 0;
	while (current_node != NULL)
	{
		number = (long int) current_node->content;
		printf("%p", current_node->content);
		printf("%ld", number);
		current_node = current_node->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstnew(void *content);

int	main(void)
{
	printf("%d", ft_lstsize(ft_lstnew((void *)10)));
	return (0);
}