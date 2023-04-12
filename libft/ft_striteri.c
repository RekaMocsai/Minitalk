/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:28:07 by rmocsai           #+#    #+#             */
/*   Updated: 2022/10/17 17:12:39 by rmocsai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s || !f)
		return ;
	if (!ft_strlen(s))
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
	return ;
}
