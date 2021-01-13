/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:31:22 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/04 20:49:21 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strs_not_null(char *dst, const char *src, \
size_t size, size_t count)
{
	size_t len_src;
	size_t len_dst;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size - 1 > len_dst)
	{
		while (count < (size - 1 - len_dst) && count < len_src)
		{
			dst[len_dst + count] = src[count];
			count++;
		}
		dst[len_dst + count] = '\0';
	}
	if (size < len_dst)
		return (size + len_src);
	else
		return (len_dst + len_src);
}

static size_t		ft_str1_is_null(char *dst, const char *src, \
size_t size, size_t count)
{
	size_t len_src;

	len_src = ft_strlen(src);
	if (size <= len_src)
		size -= 1;
	while (count != size && count != len_src)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (len_src);
}

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			count;
	size_t			len_src;
	size_t			len_dst;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	count = 0;
	if (size == 0)
		return (len_src);
	else if (len_dst == 0)
	{
		return (ft_str1_is_null(dst, src, size, count));
	}
	else if (len_src == 0)
		if (size < len_dst)
			return (size);
		else
			return (ft_strlen(dst));
	else
		return (ft_strs_not_null(dst, src, size, count));
}
