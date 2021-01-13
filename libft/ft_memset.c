/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:53:35 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/04 20:16:34 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *s1;
	unsigned char c1;

	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	while (n != 0)
	{
		*s1 = c1;
		s1++;
		n--;
	}
	return (s);
}
