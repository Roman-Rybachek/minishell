/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 02:40:01 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/06 20:38:10 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				counter;

	if (src == 0 && dest == 0)
		return (0);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	counter = n;
	if (d < s)
	{
		while (counter-- != 0)
		{
			*d = *s;
			d++;
			s++;
		}
		return (d - n);
	}
	else
	{
		while (--counter >= 0)
			d[counter] = s[counter];
		return (d);
	}
}
