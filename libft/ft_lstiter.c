/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:00:20 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/28 18:45:13 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*
static void	test(void *ptr)
{
	int x = 0;
	void *p = &x;

	ptr = p;
}

#include <stdio.h>
int	main()
{
	int x = 90;
	void *y = &x;
	char c = 'R';
	void *d = &c;
	char q = 'Q';
	void *r = &q;
	void (*f)(void *) = &test;  

	t_list *mid;
	mid = (t_list *) malloc(sizeof(t_list));
	if (!mid)
		return 0;
	t_list *last;
	last = (t_list *) malloc(sizeof(t_list));
	if (!last)
		return 0;
	t_list *head;
	head = (t_list *) malloc(sizeof(t_list));
	if (!head)
		return 0;
	
	head->content = r;
	head->next = mid;
	mid->content = y;
	mid->next = last;
	last->content = d;
	last->next = NULL;
	
	ft_lstiter(head, f);
	free(last);
	free(head);
	free(mid);
	return 0;
}
*/
