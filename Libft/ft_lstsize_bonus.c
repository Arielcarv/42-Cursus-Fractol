/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:54:24 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/28 23:40:19 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		size;

	current_node = lst;
	size = 0;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		size++;
	}
	return (size);
}
