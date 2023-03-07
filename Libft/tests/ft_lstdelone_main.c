/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:37:02 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/29 21:37:37 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	t_list	*new_list;

	new_list = ft_lstnew((void *)10);
	ft_lstdelone(new_list, free);
}