/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:00:59 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/28 13:57:27 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
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
	RM->content = d;
	RM->next = NULL;
	printf("my list: %p\n", RM->content);
	ft_lstadd_front(&head, new);
	printf("my list: %p\n", new->content);
	

	return 0;
}
 in header is the struct s_list named "t_list":
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/
