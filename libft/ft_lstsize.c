/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:37:46 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/05 01:45:52 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		count;

	p = lst;
	count = 0;
	if (lst)
		count = 1;
	else
		return (count);
	while (p->next)
	{
		count++;
		p = p->next;
	}
	return (count);
}
