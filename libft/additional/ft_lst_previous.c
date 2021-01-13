/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_previous.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:00:13 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/17 01:05:49 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_previous(t_list **all_lst, t_list **current_lst)
{
	t_list	*lst;

	lst = *all_lst;
	while (lst->next != *current_lst && lst->next != NULL)
		lst = lst->next;
	return (lst->next);
}
