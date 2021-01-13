/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:23:56 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/04 18:49:56 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		*ft_cycle(int counter, int i, int n, char *result)
{
	if (n == 0)
	{
		result[counter++] = '0';
		result[counter] = '\0';
		return (result);
	}
	while (n / i > 9)
		i *= 10;
	while (i /= 10 != 1)
	{
		result[counter++] = n / i + '0';
		n %= i;
		i /= 10;
	}
	result[counter] = '\0';
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		counter;
	int		i;

	i = 1;
	counter = 0;
	if (n < 0)
	{
		if (!(result = (char*)malloc(sizeof(char) * ft_nbrlen(n) + 2)))
			return (0);
		result[counter++] = '-';
		if (n == -2147483648)
		{
			result[counter++] = '2';
			n = 147483648;
		}
		else
			n = -n;
	}
	else
	{
		if (!(result = (char*)malloc(sizeof(char) * ft_nbrlen(n) + 1)))
			return (0);
	}
	return (ft_cycle(counter, i, n, result));
}
