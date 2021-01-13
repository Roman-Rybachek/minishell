/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:38:06 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/03 17:55:02 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		counter;

	counter = 0;
	if (!(result = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (*s != '\0')
	{
		*result = *s;
		result++;
		s++;
		counter++;
	}
	*result = '\0';
	return (result - counter);
}
