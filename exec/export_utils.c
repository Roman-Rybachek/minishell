/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 17:42:01 by casteria          #+#    #+#             */
/*   Updated: 2020/10/07 15:30:21 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char		*build_new_env(char *str)
{
	char		*new_env;

	new_env = NULL;
	new_env = ft_strchr(str, '=');
	if (!new_env)
		return (NULL);
	new_env += 1;
	new_env = ft_strdup(new_env);
	return (new_env);
}

int				do_export(t_exec *exec, t_data *data, size_t index)
{
	char		**splited;
	char		*new_env;

	splited = ft_split(exec->args[index], '=');
	if (splited == NULL)
		return (1);
	new_env = build_new_env(exec->args[index]);
	if (!parse_new_var(splited[0]))
		return (return_error(new_env, splited, data));
	else if (!new_env)
	{
		set_env(splited[0], NULL);
		ft_clr_darray(splited);
	}
	else
	{
		set_env(splited[0], new_env);
		ft_clr_darray(splited);
		free(new_env);
	}
	return (0);
}

void			free_before_exit(t_data *data, char *free_get_env)
{
	clr_t_exec(*(t_exec***)(data->clean));
	ft_3array_clr(data->clean2);
	ft_clr_darray(data->env);
	free(data->user);
	free(data->workdir);
	free(data->input_clear);
	free(free_get_env);
}

int				return_too_many_args(char *free_get_env)
{
	set_env("?", "1");
	ft_putstr_fd("exit\n", STD_OUTPUT);
	ft_putstr_fd("minishell: exit: too many arguments\n", STD_OUTPUT);
	free(free_get_env);
	return (1);
}
