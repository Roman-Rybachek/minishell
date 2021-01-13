/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:11:06 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/25 15:55:06 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_backnprint(char *fmt)
{
	int		counter;
	char	*str;

	counter = 1;
	while (*fmt != '%')
	{
		fmt -= 1;
		counter++;
	}
	str = ft_substr(fmt, 0, counter);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int			ft_ftype(char **fmt, t_fmt **fmt_flags, va_list ap)
{
	*fmt += 1;
	if (**fmt == 'c')
		return (ft_chartype(fmt_flags, ap));
	else if (**fmt == 's')
		return (ft_strtype(fmt_flags, ap));
	else if (**fmt == 'i')
		return (ft_inttype(fmt_flags, ap));
	else if (**fmt == 'd')
		return (ft_inttype(fmt_flags, ap));
	else if (**fmt == 'x')
		return (ft_hexlowtype(fmt_flags, ap));
	else if (**fmt == 'X')
		return (ft_hexuptype(fmt_flags, ap));
	else if (**fmt == 'u' || **fmt == 'U')
		return (ft_uinttype(fmt_flags, ap));
	else if (**fmt == 'p')
		return (ft_pointertype(fmt_flags, ap));
	else if (**fmt == '%')
		return (ft_procent(fmt_flags));
	else
		return (ft_backnprint(*fmt));
}
