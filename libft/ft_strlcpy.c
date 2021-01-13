/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:55:49 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/06 22:58:09 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t count;

	if (src == 0 || dst == 0)
	{
		if (src == 0)
			return (0);
		return (ft_strlen(src));
	}
	if (size == 0)
		return (ft_strlen(src));
	count = 0;
	while (count < size - 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		count++;
	}
	*dst = '\0';
	dst -= count;
	src -= count;
	return (ft_strlen(src));
}
