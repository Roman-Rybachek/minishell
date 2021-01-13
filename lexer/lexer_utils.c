/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:15:41 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 15:32:01 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		backslash(t_data *cmd, char **p)
{
	*p += 1;
	if (**p)
		cmd->str = ft_addchars(cmd->str, **p, 1);
}

void		quote(t_data *cmd, char **p)
{
	if (*(*p + 1))
	{
		*p += 1;
		while (*(*p) != '\'' && *(*p) != '\0')
		{
			cmd->str = ft_addchars(cmd->str, **p, 1);
			*p += 1;
		}
	}
}

void		add_token(t_data *cmd)
{
	if (cmd->str == NULL)
		return ;
	ft_lstadd_back(&(cmd->tokens), ft_lstnew(ft_strdup(cmd->str)));
	free(cmd->str);
	cmd->str = NULL;
}

void		redirection(t_data *cmd, char **p)
{
	if (cmd->str != NULL)
		add_token(cmd);
	cmd->str = ft_addchars(cmd->str, **p, 1);
	if (**p == '>' && *(*p + 1) == '>' && (*p += 1))
		cmd->str = ft_addchars(cmd->str, **p, 1);
	else if (**p == '>' && *(*p + 1) == '|' && (*p += 1))
		cmd->str = ft_addchars(cmd->str, **p, 1);
	else if (**p == '<' && *(*p + 1) == '>' && (*p += 1))
		cmd->str = ft_addchars(cmd->str, **p, 1);
	add_token(cmd);
}

void		double_quote(t_data *cmd, char **p)
{
	if (*(*p + 1))
	{
		*p += 1;
		while (**p != '\"' && **p != '\0')
		{
			if (**p == '$')
			{
				env_substitute(cmd, p);
				*p += 1;
			}
			else if (**p == '\\')
			{
				dquote_backslash(cmd, p);
				*p += 1;
			}
			else
			{
				cmd->str = ft_addchars(cmd->str, **p, 1);
				*p += 1;
			}
		}
	}
}
