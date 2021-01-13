/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:46:36 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/23 19:54:44 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_align(char **fmt)
{
	*fmt += 1;
	while (**fmt == '0' && (*(*fmt + 1) == '0' || *(*fmt + 1) == '-'))
		*fmt += 1;
	if (**fmt != '-')
	{
		*fmt -= 1;
		return (0);
	}
	while (*(*fmt + 1) == '-' || *(*fmt + 1) == '0')
		*fmt += 1;
	return (1);
}

static t_fmt	*ft_init_flags(char **fmt_c)
{
	t_fmt	*fmt_flags;

	if (!(fmt_flags = (t_fmt*)malloc(sizeof(t_fmt) * 1)))
		return (0);
	fmt_flags->fill_width = ' ';
	fmt_flags->align = ft_align(fmt_c);
	fmt_flags->width = 0;
	fmt_flags->accuracy = 0;
	fmt_flags->accuracy_exist = 0;
	return (fmt_flags);
}

int				ft_format(char **fmt_c, char **print_start, va_list ap)
{
	t_fmt	*fmt_flags;
	int		len;

	len = 0;
	if (!(ft_strchr("-.*0123456789%csidpuxX", *(*fmt_c + 1))))
	{
		*fmt_c += 1;
		ft_putchar_fd(**fmt_c, 1);
		return (1);
	}
	fmt_flags = ft_init_flags(fmt_c);
	fmt_flags->width = ft_fwidth(fmt_c, ap, &fmt_flags);
	fmt_flags->accuracy = ft_faccuracy(fmt_c, ap, &fmt_flags);
	len = ft_ftype(fmt_c, &fmt_flags, ap);
	*print_start = *fmt_c;
	free(fmt_flags);
	return (len);
}
