/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:28:39 by casteria          #+#    #+#             */
/*   Updated: 2020/10/08 14:55:22 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		cd2(t_exec *exec, char *dir)
{
	dir = getcwd(dir, MAX_DIR_LENGTH);
	if (chdir(exec->args[1]) < 0)
	{
		ft_printf("minishell: cd: %s: no such file or directory\n", \
															exec->args[1]);
		set_env("?", "1");
		free(dir);
	}
	else
	{
		set_env("OLDPWD", dir);
		free(dir);
		dir = getcwd(dir, MAX_DIR_LENGTH);
		set_env("PWD", dir);
	}
}

int				cd(t_exec *exec, t_data *data)
{
	char		*dir;

	dir = NULL;
	if (!exec->args[1])
	{
		set_env("OLDPWD", dir = get_env(data->env, "PWD"));
		free(dir);
		dir = get_env(data->env, "HOME");
		chdir(dir);
		free(dir);
		dir = NULL;
		dir = getcwd(dir, MAX_DIR_LENGTH);
		set_env("PWD", dir);
	}
	else if (exec->argc > 2)
	{
		ft_printf("minishell: cd: too many arguments\n");
		set_env("?", "1");
	}
	else
		cd2(exec, dir);
	if (dir)
		free(dir);
	return (data->status);
}

int				unset(t_exec *exec, t_data *data)
{
	size_t		index;
	size_t		env_s;

	index = 0;
	if (exec->args && exec->args[1])
	{
		if (!parse_new_var(exec->args[1]))
		{
			ft_printf("unset: %s: not a valid identifier\n", exec->args[1]);
			set_env("?", "1");
			return (1);
		}
		while (data->env[index])
		{
			env_s = ft_strlen(exec->args[1]);
			if (ft_strnstr(data->env[index], exec->args[1], env_s))
			{
				free(data->env[index]);
				data->env[index] = ft_strdup("1=1");
				break ;
			}
			index++;
		}
	}
	return (SUCCESSFUL_FINISH);
}

int				own_exit(t_exec *exec, t_data *data)
{
	short int	exit_code;
	char		*free_get_env;

	free_get_env = get_env(data->env, "?");
	exit_code = ft_atoi(free_get_env);
	if (exec->argc == 2)
		exit_code = ft_atoi(exec->args[1]);
	if (exec->argc > 2)
	{
		return (return_too_many_args(free_get_env));
	}
	else if (exec->argc == 2 && !ft_isdigit(*exec->args[1]))
	{
		ft_printf("minishell: exit: %s: numeric argument required\n", \
		exec->args[1]);
		exit_code = 255;
	}
	else
	{
		ft_putstr_fd("exit\n", STD_OUTPUT);
		free_before_exit(data, free_get_env);
		exit(exit_code);
	}
	free_before_exit(data, free_get_env);
	exit(exit_code);
}

int				is_parent(int (*func)(t_exec *, t_data *))
{
	if (func == &cd || func == &unset || func == &own_exit || func == \
															&own_export)
		return (1);
	return (0);
}
