/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:01:41 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/28 13:56:09 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main(void)
{

	int x = 90;
	void *y = &x;
	char c = 'R';
	void *d = &c;
	char q = 'Q';
	void *r = &q;
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
	x = ft_lstsize(head);
	printf("my list size: %d\n", x);
	free(last);
	free(head);
	free(mid);
	return (0);
}*/
