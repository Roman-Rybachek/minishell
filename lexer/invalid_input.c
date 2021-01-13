/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:18:25 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/01 20:31:35 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			check_next_symbol(char *p, char *tmp)
{
	if ((!*p || ((tmp && tmp == p && (*p == '<' || \
					*p == '>')) && !*(p + 1))) && \
		ft_printf(ERROR" `newline'\n"))
		return (0);
	else if (ft_strchr("<>|;", *p))
	{
		if (*(p + 1) && ft_strchr("<>|;", *(p + 1)))
			ft_printf(ERROR" `%c%c\'\n", *p, *p);
		else
			ft_printf(ERROR" `%c'\n", *p);
		return (0);
	}
	return (1);
}

static int			invalid_redirection(char *input, int c)
{
	char	*p;
	char	*tmp;
	char	anti_c;

	if (c == '<')
		anti_c = '>';
	else if (c == '>')
		anti_c = '>';
	p = input;
	while ((p = ft_strchr(p, c)) != NULL)
	{
		if (*(p + 1) && *(p + 1) == anti_c && p++)
			continue;
		p++;
		if (!check_next_symbol(p, NULL))
			return (0);
		tmp = p;
		ft_skip_spaces(&p);
		if (!check_next_symbol(p, tmp))
			return (0);
	}
	return (1);
}

static int			invalid_pipe(char *input)
{
	char	*p;

	p = input;
	ft_skip_spaces(&p);
	if (*p == '|')
	{
		ft_printf(ERROR" `%c'\n", *p);
		return (0);
	}
	while ((p = ft_strchr(p, '|')) != NULL)
	{
		p++;
		ft_skip_spaces(&p);
		if (*p && ft_strchr("|;", *p))
		{
			ft_printf(ERROR" `%c'\n", *p);
			return (0);
		}
	}
	return (1);
}

static int			invalid_semicolon(char *input)
{
	char	*p;

	p = input;
	ft_skip_spaces(&p);
	if (*p == ';')
	{
		ft_printf(ERROR" `%c'\n", *p);
		return (0);
	}
	while ((p = ft_strchr(p, ';')) != NULL)
	{
		p++;
		ft_skip_spaces(&p);
		if (*p && ft_strchr("|;", *p))
		{
			ft_printf(ERROR" `%c'\n", *p);
			return (0);
		}
	}
	return (1);
}

int					invalid_input(char *input)
{
	if (!invalid_redirection(input, '>') || !invalid_redirection(input, '<') \
	|| !invalid_pipe(input) || !invalid_semicolon(input))
	{
		set_env("?", "258");
		return (0);
	}
	return (1);
}
