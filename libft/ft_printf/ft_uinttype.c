/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinttype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:56:05 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/26 21:50:42 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_minus_n_null(unsigned int add, char *str,
								t_fmt **fmt_f, char *nulls)
{
	char *result;
	char *base_str;

	if ((*fmt_f)->fill_width == '0' && *str == '-')
	{
		ft_memset(nulls, (*fmt_f)->fill_width, add);
		str = ft_strjoin(nulls, ++str);
		ft_basefree(&str, &base_str);
		if (!(result = (char*)malloc(sizeof(char) * 2)))
			return (0);
		*result = '-';
		*(result + 1) = '\0';
		str = ft_strjoin(result, str);
		free(result);
	}
	else
	{
		ft_memset(nulls, (*fmt_f)->fill_width, add);
		str = ft_strjoin(nulls, str);
	}
	return (str);
}

static char		*ft_add_accuracy(unsigned int len, char *str, t_fmt **fmt_f)
{
	int		add;
	char	*result;

	add = (*fmt_f)->accuracy - len;
	if (add < 0)
		return (str);
	if (!(result = (char*)malloc(sizeof(char) * (add + 1))))
		return (0);
	ft_memset(result, '0', add);
	result[add] = '\0';
	str = ft_strjoin(result, str);
	free(result);
	return (str);
}

static int		ft_align(unsigned int len, char *str, t_fmt **fmt_f,
													char *base_str)
{
	char	*nulls;
	int		add;

	add = (*fmt_f)->width - len;
	if (!(nulls = (char*)malloc(sizeof(char) * (add + 1))))
		return (0);
	ft_memset(nulls, ' ', add);
	nulls[add] = '\0';
	if ((*fmt_f)->align)
		str = ft_strjoin(str, nulls);
	else
	{
		str = ft_minus_n_null(add, str, fmt_f, nulls);
	}
	ft_basefree(&str, &base_str);
	ft_putstr_fd(str, 1);
	add = (int)ft_strlen(str);
	free(str);
	free(nulls);
	return (add);
}

int				ft_uinttype(t_fmt **fmt_f, va_list ap)
{
	unsigned int	value;
	char			*str;
	char			*base_str;

	str = ft_itoa_l(va_arg(ap, unsigned int));
	base_str = str;
	if (*str == '0' && (*fmt_f)->accuracy_exist && (*fmt_f)->accuracy == 0)
		*str = '\0';
	value = (int)ft_strlen(str);
	if ((*fmt_f)->accuracy_exist)
	{
		if (*str != '0' && (*fmt_f)->accuracy > 0)
			(*fmt_f)->fill_width = ' ';
		if ((*fmt_f)->accuracy > 0)
			str = ft_add_accuracy(value, str, fmt_f);
		ft_basefree(&str, &base_str);
		value = (int)ft_strlen(str);
	}
	if ((unsigned int)(*fmt_f)->width > value)
		return (ft_align(value, str, fmt_f, base_str));
	else
		ft_putstr_fd(str, 1);
	free(str);
	return (value);
}
