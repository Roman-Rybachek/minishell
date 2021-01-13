/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 01:29:43 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/26 19:39:14 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*start_p;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len)
	{
		if (len > len_s - start && start < len_s)
			len = len_s - start;
		else if (start >= len_s)
			len = 0;
	}
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
	{
		free(result);
		return (0);
	}
	start_p = result;
	while (len-- && *s)
		*result++ = s[start++];
	*result = '\0';
	return (start_p);
}
