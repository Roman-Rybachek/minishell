/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clr_darray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:42:22 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/15 04:46:06 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clr_darray(char **array)
{
	int counter;

	counter = 0;
	while (array && *array)
	{
		free(*array);
		*array = NULL;
		array++;
		counter++;
	}
	array -= counter;
	free(array);
	array = NULL;
}
