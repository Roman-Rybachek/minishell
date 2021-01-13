/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ffind_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:27:04 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/20 21:32:15 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_ffind_len(char **fmt, va_list ap)
{
	int len;

	len = 0;
	*fmt += 1;
	if (**fmt == '*')
		len = va_arg(ap, int);
	else if (ft_isdigit(**fmt))
	{
		len = ft_atoi(*fmt);
		while (ft_isdigit(*(*fmt + 1)))
			*fmt += 1;
	}
	else
		*fmt -= 1;
	return (len);
}
