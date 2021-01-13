/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basefree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 20:06:16 by jeldora           #+#    #+#             */
/*   Updated: 2020/07/20 12:36:14 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_basefree(char **str, char **base_str)
{
	if (*base_str != *str && *base_str)
		free(*base_str);
	if (*str != NULL)
		*base_str = *str;
}
