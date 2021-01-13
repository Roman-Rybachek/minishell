/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:20:07 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/26 23:24:03 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_minus_n_null(int add, char *str,
						t_fmt **fmt_flags, char *nulls)
{
	char *result;
	char *base_str;

	base_str = str;
	if ((*fmt_flags)->fill_width == '0' && *str == '-')
	{
		ft_memset(nulls, (*fmt_flags)->fill_width, add);
		str = ft_strjoin(nulls, ++str);
		ft_basefree(&str, &base_str);
		if (!(result = (char*)malloc(sizeof(char) * 2)))
			return (0);
		*result = '-';
		*(result + 1) = '\0';
		str = ft_strjoin(result, str);
		ft_basefree(&str, &base_str);
		free(result);
	}
	else
	{
		ft_memset(nulls, (*fmt_flags)->fill_width, add);
		str = ft_strjoin(nulls, str);
	}
	return (str);
}

static char		*ft_add_accuracy(int len, char *str, t_fmt **fmt_flags)
{
	int		add;
	char	*result;

	add = (*fmt_flags)->accuracy - len;
	if (*str == '-')
	{
		if (!(result = (char*)malloc(sizeof(char) * (add + 2))))
			return (0);
		ft_memset(result, '0', add + 2);
		result[add + 2] = '\0';
		*result = '-';
		str = ft_strjoin(result, ++str);
		free(result);
		return (str);
	}
	else
	{
		if (!(result = (char*)malloc(sizeof(char) * (add + 1))))
			return (0);
		ft_memset(result, '0', add);
		result[add] = '\0';
		str = ft_strjoin(result, str);
		free(result);
		return (str);
	}
}

static int		ft_align(int len, char *str, t_fmt **fmt_flags,
												char *base_str)
{
	char	*nulls;
	int		add;

	add = (*fmt_flags)->width - len;
	if (!(nulls = (char*)malloc(sizeof(char) * (add + 1))))
		return (0);
	ft_memset(nulls, ' ', add);
	nulls[add] = '\0';
	if ((*fmt_flags)->align)
	{
		str = ft_strjoin(str, nulls);
		ft_basefree(&str, &base_str);
	}
	else
	{
		str = ft_minus_n_null(add, str, fmt_flags, nulls);
	}
	ft_putstr_fd(str, 1);
	add = (int)ft_strlen(str);
	free(str);
	free(nulls);
	return (add);
}

int				ft_inttype(t_fmt **fmt_flags, va_list ap)
{
	int		value;
	char	*str;
	char	*base_str;

	str = ft_itoa(va_arg(ap, int));
	base_str = str;
	if (*str == '0' && (*fmt_flags)->accuracy_exist &&
					(*fmt_flags)->accuracy == 0)
		*str = '\0';
	value = (int)ft_strlen(str);
	if ((*fmt_flags)->accuracy_exist && (*fmt_flags)->accuracy >= 0)
	{
		(*fmt_flags)->fill_width = ' ';
		if ((*fmt_flags)->accuracy > value || (*str == '-' && \
							(*fmt_flags)->accuracy > value - 1))
			str = ft_add_accuracy(value, str, fmt_flags);
		ft_basefree(&str, &base_str);
		value = (int)ft_strlen(str);
	}
	if ((*fmt_flags)->width > value)
		return (ft_align(value, str, fmt_flags, base_str));
	else
		ft_putstr_fd(str, 1);
	free(str);
	return (value);
}
