/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 22:28:53 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/29 17:25:07 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void			free_all(t_data *cmd, t_exec *exec_cmd)
{
	if (cmd)
	{
		if (cmd->tokens)
			ft_lstclear(&cmd->tokens, free);
		if (cmd->env)
			ft_clr_darray(cmd->env);
		if (cmd->workdir)
			free(cmd->workdir);
	}
	if (exec_cmd)
	{
		if (exec_cmd->exec_path)
			free(exec_cmd->exec_path);
		if (exec_cmd->args)
			ft_clr_darray(exec_cmd->args);
		free(exec_cmd);
	}
}

char			*get_env(char **envs, char *str)
{
	char	**e;
	char	**got_env;
	char	*value;

	e = envs;
	value = NULL;
	while (*e)
	{
		got_env = ft_split(*e, '=');
		if (ft_strmatch(str, got_env[0]))
		{
			if (value)
				free(value);
			if (got_env[1] != NULL)
				value = ft_strdup(got_env[1]);
		}
		ft_clr_darray(got_env);
		e++;
	}
	return (value);
}

static char		*print_dir(char *pwd, char *home)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(pwd);
	if (ft_strlen(pwd) <= ft_strlen(home))
		return (ft_strdup(pwd));
	while (home && pwd && home[i] == pwd[i])
	{
		len--;
		i++;
	}
	str = ft_substr(pwd, i, len);
	return (str);
}

void			prompt(t_data *cmd)
{
	char	*dir;
	char	*pwd;
	char	*home;
	int		home_dir_symbol;
	char	*cwd;

	home_dir_symbol = 1;
	cwd = NULL;
	pwd = getcwd(cwd, MAX_DIR_LENGTH);
	home = get_env(cmd->env, "HOME");
	if (ft_strlen(pwd) <= ft_strlen(home))
		home_dir_symbol = 0;
	dir = print_dir(pwd, home);
	ft_printf(RED"%s:", cmd->user);
	if (home_dir_symbol)
		ft_printf(CYAN"~"WHITE"%s"RED" ➜ "RESET, dir);
	else
		ft_printf(WHITE"%s"RED" ➜ "RESET, dir);
	free(pwd);
	free(home);
	free(dir);
}
