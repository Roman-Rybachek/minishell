/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlowtype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:20:22 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/26 22:28:10 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_add_accuracy(int len, char *str, t_fmt **fmt_flags)
{
	int		add;
	char	*result;
	char	*base_str;

	base_str = str;
	add = (*fmt_flags)->accuracy - len;
	if (!(result = (char*)malloc(sizeof(char) * (add + 1))))
		return (0);
	ft_memset(result, '0', add);
	result[add] = '\0';
	str = ft_strjoin(result, str);
	ft_basefree(&str, &base_str);
	free(result);
	return (str);
}

static int		ft_width(int len, char *str, t_fmt **fmt_flags)
{
	char *nulls;
	char *base_str;

	base_str = str;
	len = (*fmt_flags)->width - ft_strlen(str);
	if (!(nulls = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_memset(nulls, (*fmt_flags)->fill_width, len);
	nulls[len] = '\0';
	if ((*fmt_flags)->align)
		str = ft_strjoin(str, nulls);
	else
		str = ft_strjoin(nulls, str);
	ft_basefree(&str, &base_str);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(nulls);
	free(str);
	return (len);
}

int				ft_hexlowtype(t_fmt **fmt_flags, va_list ap)
{
	char	*str;
	int		len;

	str = ft_itoa_hex(va_arg(ap, int));
	if (*str == '0' && (*fmt_flags)->accuracy_exist &&
							(*fmt_flags)->accuracy == 0)
		*str = '\0';
	len = (int)ft_strlen(str);
	if ((*fmt_flags)->accuracy_exist)
	{
		if (*str != '0' && (*fmt_flags)->accuracy > 0 && ft_strlen(str) > 1)
			(*fmt_flags)->fill_width = ' ';
		if ((*fmt_flags)->accuracy > (int)ft_strlen(str))
			str = ft_add_accuracy(len, str, fmt_flags);
	}
	if ((*fmt_flags)->accuracy_exist && (*fmt_flags)->accuracy > 0 \
											&& ft_strlen(str) > 1)
		(*fmt_flags)->fill_width = ' ';
	len = (int)ft_strlen(str);
	if ((*fmt_flags)->width > len)
		return (ft_width(len, str, fmt_flags));
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}
