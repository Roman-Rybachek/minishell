/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:23:56 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/19 10:48:30 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(size_t n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char		ft_hex(size_t i, size_t n)
{
	int result;

	result = n / i;
	if (result == 10)
		return ('a');
	else if (result == 11)
		return ('b');
	else if (result == 12)
		return ('c');
	else if (result == 13)
		return ('d');
	else if (result == 14)
		return ('e');
	else if (result == 15)
		return ('f');
	else
		return (n / i + '0');
}

static char		*ft_cycle(int counter, size_t i, size_t n, char *result)
{
	if (n == 0)
	{
		result[counter++] = '0';
		result[counter] = '\0';
		return (result);
	}
	while (n / i > 15)
		i *= 16;
	while (i /= 16 != 1)
	{
		result[counter++] = ft_hex(i, n);
		n %= i;
		i /= 16;
	}
	result[counter] = '\0';
	return (result);
}

char			*ft_itoa_hex_t(size_t n)
{
	char	*result;
	int		counter;
	size_t	i;

	i = 1;
	counter = 0;
	if (!(result = (char*)malloc(sizeof(char) * ft_nbrlen(n) + 1)))
		return (0);
	return (ft_cycle(counter, i, n, result));
}
