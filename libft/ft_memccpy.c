/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 02:12:18 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/09 15:25:55 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	c1;

	c1 = (unsigned char)c;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n--)
	{
		if (*s == c1)
		{
			*d = *s;
			return (d + 1);
		}
		*d++ = *s++;
	}
	return (0);
}
