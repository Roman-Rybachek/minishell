/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:15:18 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/08 05:08:05 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_s1(char *result_str, char const *s1)
{
	size_t len_s1;
	size_t counter;

	counter = 0;
	len_s1 = ft_strlen(s1);
	while (counter != len_s1)
	{
		*result_str = *s1;
		result_str++;
		s1++;
		counter++;
	}
	s1 -= counter;
}

static void		ft_s2(char *result_str, char const *s2)
{
	size_t len_s2;
	size_t counter;

	counter = 0;
	len_s2 = ft_strlen(s2);
	while (counter != len_s2)
	{
		*result_str = *s2;
		result_str++;
		s2++;
		counter++;
	}
	s2 -= counter;
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == 0 && s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result_str = (char*)malloc(sizeof(*result_str) * (len_s1 + len_s2) + 1);
	if (result_str == 0)
		return (0);
	ft_s1(result_str, s1);
	result_str += len_s1;
	ft_s2(result_str, s2);
	result_str += len_s2;
	*result_str = '\0';
	result_str -= len_s1 + len_s2;
	return (result_str);
}
