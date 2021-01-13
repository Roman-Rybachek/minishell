/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwidth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:58:59 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/26 19:39:08 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_ifnull(char **fmt, va_list ap)
{
	while (*(*fmt + 1) == '0')
		*fmt += 1;
	return (ft_ffind_len(fmt, ap));
}

int				ft_fwidth(char **fmt, va_list ap,
								t_fmt **fmt_flags)
{
	int len;

	len = 0;
	*fmt += 1;
	if (**fmt == '0')
	{
		(*fmt_flags)->fill_width = '0';
		len = ft_ifnull(fmt, ap);
	}
	else if (**fmt == '*' || ft_isdigit(**fmt))
	{
		*fmt -= 1;
		len = ft_ffind_len(fmt, ap);
	}
	else
		*fmt -= 1;
	if (len < 0)
	{
		(*fmt_flags)->align = 1;
		len = -len;
	}
	return (len);
}
