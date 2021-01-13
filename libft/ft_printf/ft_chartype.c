/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:46:02 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/27 19:47:20 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_align_right(t_fmt **fmt_flags, char *str, char c)
{
	int len;

	len = 0;
	ft_memset(str, ' ', (*fmt_flags)->width - 1);
	str[(*fmt_flags)->width - 1] = c;
	str[(*fmt_flags)->width] = '\0';
	ft_putstr_fd(str, 1);
	if (c == 0)
	{
		ft_putchar_fd('\0', 1);
		len += 1;
	}
	len += ft_strlen(str);
	free(str);
	return (len);
}

static int		ft_align_left(t_fmt **fmt_flags, char *str, char c)
{
	int len;

	len = 0;
	ft_memset(str, ' ', (*fmt_flags)->width);
	if (c == 0)
	{
		ft_putchar_fd('\0', 1);
		len = ft_strlen(str);
		str++;
		ft_putstr_fd(str, 1);
		str--;
		free(str);
		return (len);
	}
	else
	{
		str[(*fmt_flags)->width] = '\0';
		*str = c;
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (len);
}

int				ft_chartype(t_fmt **fmt_flags, va_list ap)
{
	char c;
	char *str;

	c = va_arg(ap, int);
	if ((*fmt_flags)->width > 1)
	{
		if (!(str = (char*)malloc(sizeof(char) * ((*fmt_flags)->width + 1))))
			return (0);
		if ((*fmt_flags)->align > 0)
			return (ft_align_left(fmt_flags, str, c));
		else
			return (ft_align_right(fmt_flags, str, c));
	}
	else
		ft_putchar_fd(c, 1);
	return (1);
}
