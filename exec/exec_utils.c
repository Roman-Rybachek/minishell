/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:57:31 by casteria          #+#    #+#             */
/*   Updated: 2020/10/08 20:23:58 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void				debug_exit(void)
{
	ft_putstr_fd(strerror(errno), STD_ERR);
	ft_putchar_fd('\n', STD_OUTPUT);
	exit(1);
}

void				command_not_found(const char *cmd)
{
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd((char *)cmd, STD_ERR);
	ft_putstr_fd(": command not found\n", STD_ERR);
}

static void			do_on_main_process(t_exec **exec, t_data *data, int index)
{
	char			*free_itoa;

	free_itoa = NULL;
	if (index != data->count_of_process - 1 && \
								exec[index + 1])
	{
		close(data->pipe[1]);
		dup2(data->pipe[0], 0);
		close(data->pipe[0]);
	}
	data->current_process = (*exec)->pid;
	wait(&(*exec)->pid);
	data->status = WEXITSTATUS((*exec)->pid);
	if (data->status != 0)
	{
		set_env("?", free_itoa = ft_itoa(data->status));
		if (free_itoa)
			free(free_itoa);
	}
	data->current_process = 0;
	close(data->pipe[0]);
	close(data->pipe[1]);
}

void				try_to_execute(int (*func)(t_exec *, t_data *), \
									t_exec **exec, t_data *data, int index)
{
	pipe(data->pipe);
	set_env("?", "0");
	(*exec)->pid = fork();
	if (!(*exec)->pid)
	{
		if (index != data->count_of_process - 1 \
							&& exec[index + 1])
		{
			close(data->pipe[0]);
			dup2(data->pipe[1], 1);
			close(data->pipe[1]);
		}
		execute_child(func, exec[index], data);
	}
	else if ((*exec)->pid < 0)
		debug_exit();
	else
		do_on_main_process(exec, data, index);
}

int					return_error(char *new_env, char **splited, t_data *data)
{
	ft_printf("%export: '%s': not a valid identifier\n", splited[0]);
	(void)data;
	set_env("?", "1");
	if (new_env)
		free(new_env);
	ft_clr_darray(splited);
	return (1);
}
