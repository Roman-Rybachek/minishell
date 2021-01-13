/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:42:31 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/05 15:50:45 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *p;

	p = lst;
	if (!lst)
		return ;
	while (p->next)
	{
		if (p->content)
			f(p->content);
		p = p->next;
	}
	if (p->content)
		f(p->content);
}
