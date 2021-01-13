/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_occur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 03:08:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/10 03:53:51 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		content_count(t_list *lst, void *content)
{
	int		count;
	t_list	*occurence;

	count = 0;
	occurence = ft_cntsrch(lst, content);
	while (occurence)
	{
		count++;
		occurence = occurence->next;
		occurence = ft_cntsrch(occurence, content);
	}
	return (count);
}

int				ft_cnt_occur(t_list *lst, void *content, \
									t_list **get_occur)
{
	int		count;
	t_list	*occurence;
	int		i;

	i = 0;
	count = content_count(lst, content);
	if (!get_occur)
		return (count);
	if (!(get_occur = (t_list**)malloc(sizeof(t_list*) * (count + 1))))
		return (count);
	occurence = ft_cntsrch(lst, content);
	while (occurence)
	{
		get_occur[i++] = occurence;
		occurence = occurence->next;
		occurence = ft_cntsrch(occurence, content);
	}
	get_occur[i] = NULL;
	return (count);
}
