/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 05:40:15 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/21 05:48:08 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free(void *obj_to_free)
{
	if (obj_to_free != NULL)
	{
		free(obj_to_free);
		obj_to_free = NULL;
	}
	return (1);
}
