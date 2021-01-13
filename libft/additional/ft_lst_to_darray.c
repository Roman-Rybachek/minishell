/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_darray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 03:51:27 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/15 03:44:35 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_darray(t_list *lst)
{
	char	**darray;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	darray = malloc(sizeof(char*) * (ft_lstsize(lst) + 1));
	while (lst)
	{
		darray[i++] = lst->content;
		lst = lst->next;
	}
	darray[i] = NULL;
	return (darray);
}
