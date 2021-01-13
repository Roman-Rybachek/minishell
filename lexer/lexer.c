/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 09:19:49 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/03 18:31:06 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

extern t_data		g_cmd;

static void			input_follow_pipe(char **input)
{
	char *c;

	c = NULL;
	c = ft_strchr(*input, '>');
	if (c != NULL && *(c + 1) == '|')
		*(c + 1) = ' ';
}

static int			last_pipe(char **input)
{
	char	*p;
	char	*new_input;
	char	*tmp;

	p = NULL;
	while ((p = ft_strrchr(*input, '|')) != NULL)
	{
		while (++p && *p)
			if (*p != ' ')
				return (1);
		ft_printf("> ");
		get_next_line(0, &new_input);
		tmp = *input;
		*input = ft_strjoin(*input, new_input);
		free(tmp);
		input_follow_pipe(input);
		if (!invalid_input(*input))
			return (0);
	}
	return (1);
}

static void			is_spec_symbol(char **p, t_data *cmd)
{
	if (**p == '\\')
		backslash(cmd, p);
	else if (**p == '\'')
		quote(cmd, p);
	else if (ft_strchr("<>|", **p))
		redirection(cmd, p);
	else if (**p == ' ')
		add_token(cmd);
	else if (**p == '$')
		env_substitute(cmd, p);
	else if (**p == '\"')
		double_quote(cmd, p);
	else if (**p == ';')
	{
		add_token(cmd);
		parser(cmd);
	}
}

static int			processing_symbols(char **p, t_data *cmd)
{
	if (ft_strchr("\\ \" \' < > | $ ;", **p))
		is_spec_symbol(p, cmd);
	else
		cmd->str = ft_addchars(cmd->str, **p, 1);
	return (1);
}

int					lexer(char **input, t_data *cmd)
{
	char	*p;

	cmd->status = 0;
	input_follow_pipe(input);
	if (!invalid_input(*input))
		return (0);
	if (!last_pipe(input))
		return (0);
	p = *input;
	while (p && *p)
	{
		if (g_cmd.status == 130 || g_cmd.status == 131)
			return (1);
		processing_symbols(&p, cmd);
		if (*p != '\0')
			p++;
	}
	if (cmd->str != NULL)
		add_token(cmd);
	parser(cmd);
	return (1);
}
