/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_srch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 02:10:50 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/10 03:08:46 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_cntsrch(t_list *lst, void *content)
{
	t_list *l;

	l = lst;
	while (l != NULL)
	{
		if (ft_strncmp((char*)l->content, (char*)content, \
							ft_strlen((char*)content)) == 0)
			return (l);
		l = l->next;
	}
	return (NULL);
}
