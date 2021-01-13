/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:13:26 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/08 00:35:27 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_darray_dup(char **array)
{
	char	**result;
	int		i;

	i = ft_height_darray(array);
	if (!(result = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	result[i] = NULL;
	i = 0;
	while (array && array[i])
	{
		result[i] = ft_strdup(array[i]);
		i++;
	}
	return (result);
}
