/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_faccuracy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:22:59 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/18 01:29:49 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_faccuracy(char **fmt, va_list ap, t_fmt **fmt_flags)
{
	*fmt += 1;
	if (**fmt == '.')
	{
		(*fmt_flags)->accuracy_exist = 1;
		return (ft_ffind_len(fmt, ap));
	}
	else
		*fmt -= 1;
	return (0);
}
