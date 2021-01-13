/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3array_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 22:43:47 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/26 17:17:41 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_3array_clr(char ***array)
{
	char	***tmp;

	tmp = array;
	while (array && *array)
	{
		ft_clr_darray(*array);
		array++;
	}
	free(tmp);
}
