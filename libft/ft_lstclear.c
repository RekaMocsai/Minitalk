/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:01:09 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/30 10:15:48 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_lst;

	current = *lst;
	while (current != NULL)
	{
		next_lst = current->next;
		ft_lstdelone(current, del);
		current = next_lst;
	}
	*lst = NULL;
}
