/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:38:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/29 22:25:33 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;
	t_list	*current_node;

	current_node = *lst;
	if (current_node && del)
	{
		while (current_node)
		{
			next_node = current_node->next;
			ft_lstdelone(current_node, del);
			current_node = next_node;
		}
		*lst = NULL;
	}
}
