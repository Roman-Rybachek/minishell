/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 11:39:12 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/20 11:37:08 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_print(char **fmt_c, char **print_start,
							va_list ap, int *len_to_proc)
{
	int		total_len;
	char	*str_to_prnt;

	total_len = *len_to_proc;
	str_to_prnt = ft_substr(*print_start, 0, *len_to_proc);
	ft_putstr_fd(str_to_prnt, 1);
	free(str_to_prnt);
	total_len += ft_format(fmt_c, print_start, ap);
	*len_to_proc = 0;
	if (**fmt_c != '\0')
		*fmt_c += 1;
	*print_start = *fmt_c;
	return (total_len);
}

static void		ft_else(char **fmt_c, int *len_to_proc, char **print_start,
						int *total_len)
{
	char *str_to_prnt;

	*fmt_c += 1;
	*len_to_proc += 1;
	if (**fmt_c == '\0')
	{
		str_to_prnt = ft_substr(*print_start, 0, *len_to_proc);
		ft_putstr_fd(str_to_prnt, 1);
		free(str_to_prnt);
		*total_len += *len_to_proc;
	}
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*fmt_c;
	char		*print_start;
	int			len_to_proc;
	int			total_len;

	total_len = 0;
	len_to_proc = 0;
	fmt_c = (char*)fmt;
	print_start = fmt_c;
	va_start(ap, fmt);
	while (*fmt_c)
	{
		if (*fmt_c == '%')
			total_len += ft_print(&fmt_c, &print_start, ap, &len_to_proc);
		else
			ft_else(&fmt_c, &len_to_proc, &print_start, &total_len);
	}
	va_end(ap);
	return (total_len);
}
