/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:52:12 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/09 19:04:51 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*element;

	if (!lst || !f || !del)
		return (NULL);
	if (!(element = ft_lstnew(f(lst->content))))
		return (NULL);
	lst_new = element;
	while (lst->next)
	{
		lst = lst->next;
		if (!(element->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		element = element->next;
	}
	return (lst_new);
}
