/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 00:09:59 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/21 05:47:44 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_of_char(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

static size_t	ft_count_of_str(char const *s, char c)
{
	size_t w_counter;

	w_counter = 0;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			w_counter++;
			while (*s != c && *s != '\0')
			{
				s++;
			}
		}
		else
		{
			while (*s == c)
			{
				s++;
			}
		}
	}
	return (w_counter);
}

static char		*ft_write_str(char const *s, char *str, size_t len)
{
	size_t counter;

	counter = 0;
	while (counter != len)
	{
		*str = *s;
		str++;
		s++;
		counter++;
	}
	*str = '\0';
	str -= counter;
	return (str);
}

static void		*ft_free_func(char **result)
{
	size_t counter;

	counter = 0;
	while (result[counter])
	{
		free(result[counter]);
		counter++;
	}
	free(result);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	char	*str;
	size_t	count_of_str;

	if (s == 0)
		return (0);
	count_of_str = ft_count_of_str(s, c);
	if (!(result = (char**)malloc(sizeof(char*) * (count_of_str + 1))))
		return (0);
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (!(str = (char*)malloc(sizeof(char) * \
			(ft_count_of_char(s, c) + 1))))
				return (ft_free_func(result));
			*result = ft_write_str(s, str, ft_count_of_char(s, c));
			result++;
			s += ft_count_of_char(s, c);
		}
		else
			s++;
	}
	*result = 0;
	return (result - count_of_str);
}
