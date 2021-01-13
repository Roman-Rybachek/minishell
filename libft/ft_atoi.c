/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 04:57:23 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/03 02:00:05 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_plusminus(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int				ft_atoi(const char *str)
{
	char			*p;
	int				minus;
	unsigned long	result;

	result = 0;
	minus = 1;
	p = (char*)str;
	while (*p == '\t' || *p == '\n' || *p == '\v' || *p == '\f' \
	|| *p == '\r' || *p == ' ')
		p++;
	if (*p == '-' || *p == '+')
	{
		minus = ft_plusminus(*p);
		p++;
	}
	while (*p >= 48 && *p <= 57)
	{
		if (result > (result * 10 + (*p - '0')))
			return (minus > 0 ? -1 : 0);
		result = result * 10 + (*p - '0');
		p++;
	}
	result = result * minus;
	return (result);
}
