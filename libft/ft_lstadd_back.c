/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:01:16 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/28 14:41:46 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last)
		last->next = new;
	else
		*lst = new;
}
/*
#include <stdio.h>
int	main(void)
{

	int x = 90;
	void *y = &x;
	char c = 'R';
	void *d = &c;
	char q = 'Q';
	void *r = &q;
	t_list *new;
	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return 0;
	t_list *RM;
	RM = (t_list *) malloc(sizeof(t_list));
	if (!RM)
		return 0;
	t_list *head;
	head = (t_list *) malloc(sizeof(t_list));
	if (!head)
		return 0;

	head->content = r;
	head->next = RM;
	new->content = y;
	printf("my list: %p\n", new->content);
	RM->content = d;
	RM->next = NULL;
	ft_lstadd_back(&head, new);
	printf("my list: %p\n", new->content);
	free (new);	
	free(RM);
	free(head);
	return 0;
}
in header is the struct s_list named "t_list":
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/
