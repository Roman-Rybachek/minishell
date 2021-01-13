/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 00:55:45 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/05 23:06:19 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list		*element;

	element = (t_list*)malloc(sizeof(t_list) * 1);
	if (element == 0)
		return (0);
	element->content = content;
	element->next = 0;
	return (element);
}
