/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 03:04:57 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/06 23:36:22 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	counter;

	if (s == 0)
		return (0);
	counter = 0;
	len = ft_strlen(s);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (counter != len)
	{
		result[counter] = f(counter, s[counter]);
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
