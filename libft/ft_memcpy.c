/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 02:02:09 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/06 17:28:05 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			counter;

	if (src == 0 && dest == 0)
		return (0);
	counter = n;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (counter-- != 0)
	{
		*d = *s;
		d++;
		s++;
	}
	d -= n;
	s -= n;
	return (d);
}
