/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:23:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/04/30 04:54:38 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		len;

	len = ft_strlen(s);
	p = (char*)s;
	while (len >= 0)
	{
		if (p[len] == c)
			return (&p[len]);
		else
			len--;
	}
	return (0);
}
