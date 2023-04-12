/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:01:25 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/28 14:36:07 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int x = 2;
	int m = 3;
	int a = 4;
	void *y = &x;
	void *n = &m;
	void *b = &a;

	t_list	*head;
	head = (t_list *) malloc(sizeof(t_list));
	if (!head)
		return 0;
	t_list	*mid;
	mid = (t_list *) malloc(sizeof(t_list));
	if (!mid)
		return 0;
	t_list	*last;
	last = (t_list *) malloc(sizeof(t_list));
	if(!last)
		return 0;
	head->content = y;
	head->next = mid;
	mid->content = n;
	mid->next = last;
	last->content = b;
	last->next = NULL;
	t_list	*temp;
	temp = ft_lstlast(head);
	printf("my last is  %p\n", last->content);
	printf("returned is %p\n", temp->content);
	free (last);
	free (mid);
	free (head);
	return 0;
}
*/
