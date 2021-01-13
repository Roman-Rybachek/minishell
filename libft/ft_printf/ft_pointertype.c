/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointertype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 01:45:56 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/26 22:43:36 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_add_accuracy(t_fmt **fmt_flags, char *str)
{
	char	*result;
	int		accuracy;

	accuracy = (*fmt_flags)->accuracy;
	if (accuracy > 0 && accuracy >= (int)ft_strlen(str))
	{
		accuracy = (*fmt_flags)->accuracy - (int)ft_strlen(str);
		if (!(result = (char*)malloc(sizeof(char) * ((accuracy + 3)))))
			return (0);
		ft_memset(result, '0', accuracy + 2);
		result[1] = 'x';
		result[accuracy + 2] = '\0';
		str = ft_strjoin(result, str);
		free(result);
	}
	else if (*str == '0')
	{
		if (!(str = (char*)malloc(sizeof(char) * (3))))
			return (0);
		str[0] = '0';
		str[1] = 'x';
		str[2] = '\0';
	}
	return (str);
}

static char		*ft_add_width_if(t_fmt **fmt_flags, char *str, char *nulls)
{
	int		width;
	char	*base_str;

	base_str = str;
	width = (*fmt_flags)->width - (int)ft_strlen(str);
	ft_memset(nulls, ' ', width);
	nulls[width] = '\0';
	if ((*fmt_flags)->align)
		str = ft_strjoin(str, nulls);
	else
		str = ft_strjoin(nulls, str);
	ft_basefree(&str, &base_str);
	return (str);
}

static char		*ft_add_width(t_fmt **fmt_flags, char *str)
{
	char	*nulls;
	int		width;
	char	*base_str;

	width = (*fmt_flags)->width - (int)ft_strlen(str);
	if (!(nulls = (char*)malloc(sizeof(char) * (width + 1))))
		return (0);
	if ((*fmt_flags)->align || (*fmt_flags)->accuracy_exist)
		str = ft_add_width_if(fmt_flags, str, nulls);
	else if ((base_str = str))
	{
		ft_memset(nulls, (*fmt_flags)->fill_width, width - 1);
		nulls[width] = '\0';
		if ((*fmt_flags)->fill_width == ' ')
		{
			nulls[width - 1] = 'x';
			nulls[width - 2] = '0';
		}
		else
			nulls[1] = 'x';
		str = ft_strjoin(nulls, str);
		ft_basefree(&str, &base_str);
	}
	free(nulls);
	return (str);
}

static char		*ft_vanil(char *str)
{
	char *nulls;
	char *base_str;

	base_str = str;
	if (!(nulls = (char*)malloc(sizeof(char) * 3)))
		return (0);
	nulls[0] = '0';
	nulls[1] = 'x';
	nulls[2] = '\0';
	str = ft_strjoin(nulls, str);
	ft_basefree(&str, &base_str);
	free(nulls);
	return (str);
}

int				ft_pointertype(t_fmt **fmt_flags, va_list ap)
{
	char	*str;
	size_t	value;
	char	*base_str;

	str = ft_itoa_hex_t(va_arg(ap, size_t));
	if ((base_str = str) && (*fmt_flags)->accuracy_exist)
		str = ft_add_accuracy(fmt_flags, str);
	ft_basefree(&str, &base_str);
	if ((*fmt_flags)->align || (*fmt_flags)->accuracy_exist)
	{
		if (*(str + 1) != 'x')
			str = ft_strjoin("0x", str);
		ft_basefree(&str, &base_str);
		if ((*fmt_flags)->width > (int)ft_strlen(str))
			str = ft_add_width(fmt_flags, str);
	}
	else if ((*fmt_flags)->width > (int)ft_strlen(str) + 2)
		str = ft_add_width(fmt_flags, str);
	else
		str = ft_vanil(str);
	ft_putstr_fd(str, 1);
	value = (int)ft_strlen(str);
	free(str);
	return (value);
}
