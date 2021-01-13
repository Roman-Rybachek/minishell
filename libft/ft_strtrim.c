/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:51:58 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/19 10:50:23 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

static int		ft_start_index(char const *s1, char const *set)
{
	int index;

	index = 0;
	while (ft_in_set(*s1, set))
	{
		index++;
		s1++;
	}
	return (index);
}

static int		ft_end_index(char const *s1, char const *set)
{
	int index;

	index = ft_strlen(s1) - 1;
	while (ft_in_set(s1[index], set))
	{
		index--;
	}
	return (index);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	len;
	size_t	end_index;
	size_t	start_index;

	if (s1 == 0)
		return (0);
	start_index = ft_start_index(s1, set);
	end_index = ft_end_index(s1, set);
	len = end_index - start_index;
	if (start_index == ft_strlen(s1))
	{
		if (!(result = (char*)malloc(sizeof(char) * 1)))
			return (0);
		*result = '\0';
		return (result);
	}
	if (!(result = (char*)malloc(sizeof(char) * (len + 2))))
		return (0);
	while (start_index <= end_index)
	{
		*result++ = s1[start_index++];
	}
	*result = '\0';
	return (result - len - 1);
}
