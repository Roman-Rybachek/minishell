/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 04:34:57 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/27 19:47:13 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isnull(unsigned char s1, unsigned char s2)
{
	if (s1 == '\0' && s2 == '\0')
		return (0);
	else if (s1 == '\0')
		return (-1);
	else if (s2 == '\0')
		return (1);
	else
		return (s1 - s2);
}

static int		ft_len_is_null(unsigned char *s1, unsigned char *s2)
{
	if (s1[0] == '\0' && s2[0] != '\0')
		return (-1);
	else if (s1[0] != '\0' && s2[0] == '\0')
		return (1);
	else if (s1 == 0 || s2 == 0)
		return (0);
	else
		return (0);
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			c;

	c = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	if (p1[0] == '\0' || p2[0] == '\0')
		return (ft_len_is_null(p1, p2));
	while (c < n)
	{
		if (p1[c] != p2[c])
		{
			return (ft_isnull(p1[c], p2[c]));
		}
		else
		{
			if (p2[c] == '\0' && p1[c] == '\0')
				return (0);
			c++;
		}
	}
	return (0);
}
