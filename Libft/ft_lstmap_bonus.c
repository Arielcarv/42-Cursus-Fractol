/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:16:18 by arcarval          #+#    #+#             */
/*   Updated: 2023/03/04 14:57:35 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*function)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux;

	new_lst = NULL;
	while (lst)
	{
		aux = ft_lstnew(function(lst->content));
		if (!aux)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, aux);
		lst = lst->next;
	}
	return (new_lst);
}
