/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:00:40 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/28 13:56:47 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
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
	t_list *RM;
	RM = (t_list *) malloc(sizeof(t_list));
	if (!RM)
		return 0;
	t_list *head;
	head = (t_list *) malloc(sizeof(t_list));
	if (!head)
		return 0;
	
	t_list *new = ft_lstnew(y);
	head->content = r;
	head->next = RM;
	RM->content = d;
	RM->next = NULL;
	printf("my list: %p\n", RM->content);
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
