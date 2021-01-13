/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:53:28 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/25 20:21:37 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				check_program_path(t_exec *cmd_exec, char *token)
{
	DIR	*dir;

	if ((dir = opendir(token)) != NULL)
	{
		closedir(dir);
		set_env("?", "126");
		ft_printf("minishell: %s: is a directory\n", token);
		cmd_exec->exec_path = ft_strdup("(empty)");
		return (0);
	}
	else if (!ft_fexist(token))
	{
		set_env("?", "127");
		ft_printf("minishell: %s: No such file or directory\n", token);
		cmd_exec->exec_path = ft_strdup("(empty)");
		return (0);
	}
	else
		cmd_exec->exec_path = ft_strdup(token);
	return (1);
}

static void		just_clr(char ***paths, char **env)
{
	ft_clr_darray(*paths);
	free(*env);
}

int				finding_in_system(t_exec *cmd_exec, char *token, t_data *cmd)
{
	char	*env;
	char	**paths;
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = 0;
	env = get_env(cmd->env, "PATH");
	paths = ft_split(env, ':');
	while (paths && paths[i])
	{
		tmp1 = ft_strjoin("/", token);
		tmp2 = ft_strjoin(paths[i], tmp1);
		free(tmp1);
		if (ft_fexist(tmp2) && (cmd_exec->exec_path = tmp2))
		{
			just_clr(&paths, &env);
			return (1);
		}
		free(tmp2);
		i++;
	}
	just_clr(&paths, &env);
	return (0);
}

int				finding_in_our_func(t_exec *exec_cmd, char *token)
{
	if (ft_strmatch(token, "echo") || \
		ft_strmatch(token, "pwd") || \
		ft_strmatch(token, "cd") || \
		ft_strmatch(token, "export") || \
		ft_strmatch(token, "unset") || \
		ft_strmatch(token, "env") || \
		ft_strmatch(token, "exit"))
	{
		exec_cmd->exec_path = ft_strdup(token);
		return (1);
	}
	else
		return (0);
}

int				set_input(t_exec *cmd_exec, char *token)
{
	if (!ft_fexist(token))
	{
		set_env("?", "1");
		ft_printf("minishell: %s: No such file or directory\n", token);
		return (0);
	}
	if (cmd_exec->input)
		close(cmd_exec->input);
	cmd_exec->input = open(token, O_RDONLY);
	if (!cmd_exec->input)
		return (0);
	return (1);
}
