/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 18:05:54 by jeldora           #+#    #+#             */
/*   Updated: 2020/08/30 18:27:02 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct		s_fmt
{
	int				width;
	int				align;
	int				accuracy;
	int				accuracy_exist;
	char			fill_width;
}					t_fmt;

void				ft_basefree(char **str, char **base_str);
int					ft_procent(t_fmt **fmt_flags);
int					ft_pointertype(t_fmt **fmt_flags, va_list ap);
int					ft_strtype(t_fmt **fmt_flags, va_list ap);
int					ft_chartype(t_fmt **fmt_flags, va_list ap);
int					ft_inttype(t_fmt **fmt_flags, va_list ap);
int					ft_hexlowtype(t_fmt **fmt_flags, va_list ap);
int					ft_hexuptype(t_fmt **fmt_flags, va_list ap);
int					ft_uinttype(t_fmt **fmt_flags, va_list ap);

int					ft_fwidth(char **fmt, va_list ap, t_fmt **fmt_flags);
int					ft_ffind_len(char **fmt, va_list ap);
int					ft_faccuracy(char **fmt, va_list ap, t_fmt **fmt_flags);
int					ft_ftype(char **fmt, t_fmt **fmt_flags, va_list ap);

int					ft_printf(const char *fmt, ...);
int					ft_format(char **fmt_c, char **print_start, va_list ap);

#endif
