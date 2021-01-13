/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_env_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 05:58:37 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 15:35:07 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int		longer_found(char **p, char **got_env, char **longest)
{
	int		len;

	len = 0;
	if (ft_strnstr(*p, got_env[0], ft_strlen(got_env[0])) \
	&& ft_strlen(got_env[0]) > ft_strlen(*longest))
	{
		if (*longest)
			free(*longest);
		*longest = ft_strdup(got_env[1]);
		len = ft_strlen(got_env[0]);
	}
	ft_clr_darray(got_env);
	return (len);
}

static void		longest_found(t_data *cmd, char **p, char **longest, \
												int *add_len)
{
	char	*tmp;

	if (ft_isalnum(*(*p + *add_len)))
	{
		free(*longest);
		*longest = NULL;
	}
	if (*longest == NULL)
	{
		while (!ft_strchr("\' \" <>| $ ; \\", **p))
			*p += 1;
		*add_len = 0;
		return ;
	}
	tmp = cmd->str;
	cmd->str = ft_strjoin(cmd->str, *longest);
	free(*longest);
	if (tmp)
		free(tmp);
}

static int		is_dollar_alone(t_data *cmd, char **p)
{
	if (!*(*p + 1) || *(*p + 1) == ' ' || *(*p + 1) == '"')
	{
		cmd->str = ft_addchars(cmd->str, '$', 1);
		return (1);
	}
	return (0);
}

static char		**cut_env(char *env)
{
	char *p;
	char **value;
	char **buffer;

	p = NULL;
	buffer = ft_split(env, '=');
	p = ft_strchr(env, '=');
	if (p)
		value = (char **)malloc(sizeof(char *) * 3);
	else
		value = (char **)malloc(sizeof(char *) * 2);
	value[0] = ft_strdup(buffer[0]);
	if (p)
	{
		value[1] = ft_strdup(++p);
		value[2] = NULL;
	}
	else
		value[1] = NULL;
	ft_clr_darray(buffer);
	return (value);
}

void			env_substitute(t_data *cmd, char **p)
{
	char	**env;
	char	**got_env;
	char	*longest;
	int		len;
	int		add_len;

	add_len = 0;
	if (is_dollar_alone(cmd, p))
		return ;
	*p += 1;
	env = cmd->env;
	longest = NULL;
	while (*env)
	{
		got_env = cut_env(*env);
		len = longer_found(p, got_env, &longest);
		add_len = len > 0 ? len : add_len;
		env += 1;
	}
	longest_found(cmd, p, &longest, &add_len);
	*p += add_len - 1;
}
