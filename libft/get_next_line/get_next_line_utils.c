/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:08:38 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/02 16:41:35 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char		*ft_strchr(const char *s, int c)
{
	char	*p;
	int		len;

	len = ft_strlen(s);
	p = (char*)s;
	while (len >= 0)
	{
		if (*p == c)
		{
			return (p);
		}
		else
		{
			p++;
			len--;
		}
	}
	return (0);
}

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
