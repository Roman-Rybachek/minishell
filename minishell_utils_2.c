/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:16:26 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 15:27:01 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

extern t_data g_cmd;

void				change_env(char *what, char *new1, char **env)
{
	size_t			index1;
	char			*new_env;
	size_t			env_s;
	size_t			new_s;

	index1 = 0;
	env_s = ft_strlen(what);
	new_s = ft_strlen(new1);
	new_env = NULL;
	while (env[index1])
	{
		if (ft_strnstr(env[index1], what, env_s))
		{
			free(env[index1]);
			new_env = malloc(sizeof(char) * (env_s + new_s + 2));
			ft_strlcpy(new_env, what, env_s + 1);
			new_env[env_s] = '=';
			ft_strlcpy(&new_env[env_s + 1], new1, new_s + 1);
			env[index1] = new_env;
		}
		index1++;
	}
}

void				add_env(char *name, char *value)
{
	char	**new_envs;
	int		height;
	char	*tmp;

	height = ft_height_darray(g_cmd.env);
	new_envs = ft_darray(height + 1);
	if (value)
	{
		tmp = ft_strjoin(name, "=");
		new_envs[height] = ft_strjoin(tmp, value);
		free(tmp);
	}
	else
		new_envs[height] = ft_strdup(name);
	while (--height > -1)
		new_envs[height] = ft_strdup(g_cmd.env[height]);
	ft_clr_darray(g_cmd.env);
	g_cmd.env = new_envs;
}

static int			exists_env(char **envs, char *name)
{
	char	**e;
	char	**got_env;

	e = envs;
	while (*e)
	{
		got_env = ft_split(*e, '=');
		if (ft_strmatch(name, got_env[0]))
		{
			ft_clr_darray(got_env);
			return (1);
		}
		ft_clr_darray(got_env);
		e++;
	}
	return (0);
}

int					set_env(char *name, char *value)
{
	char	*val;

	val = NULL;
	val = get_env(g_cmd.env, name);
	if (val != NULL)
	{
		free(val);
		val = NULL;
		change_env(name, value, g_cmd.env);
		return (1);
	}
	else if (exists_env(g_cmd.env, name))
	{
		if (value)
			change_env(name, value, g_cmd.env);
		return (1);
	}
	add_env(name, value);
	val = get_env(g_cmd.env, name);
	if (val != NULL)
	{
		free(val);
		return (1);
	}
	return (0);
}
