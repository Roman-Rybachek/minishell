/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:24:48 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/23 18:31:20 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_align_right(t_fmt **fmt_flags, char *str, char c)
{
	int len;

	len = 0;
	ft_memset(str, (*fmt_flags)->fill_width, (*fmt_flags)->width - 1);
	str[(*fmt_flags)->width - 1] = c;
	str[(*fmt_flags)->width] = '\0';
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}

static int		ft_align_left(t_fmt **fmt_flags, char *str, char c)
{
	int len;

	len = 0;
	ft_memset(str, ' ', (*fmt_flags)->width);
	str[(*fmt_flags)->width] = '\0';
	*str = c;
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int				ft_procent(t_fmt **fmt_flags)
{
	char c;
	char *str;

	c = '%';
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
