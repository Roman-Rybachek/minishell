/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:17:53 by jeldora           #+#    #+#             */
/*   Updated: 2020/07/20 19:17:47 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_darray(int value_of_str)
{
	char	**result;

	if (!(result = (char**)malloc(sizeof(char*) * (value_of_str + 1))))
		return (NULL);
	result[value_of_str] = NULL;
	return (result);
}
