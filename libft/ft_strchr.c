/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:09:18 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/04 00:11:20 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
