/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:04:56 by casteria          #+#    #+#             */
/*   Updated: 2020/10/06 20:04:52 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void			exec_own_child(int (*func)(t_exec *, t_data *), \
			t_exec *exec, t_data *data, int *saved)
{
	func(exec, data);
	close(exec->output);
	close(STD_OUTPUT);
	dup2(saved[0], STD_OUTPUT);
	close(saved[1]);
	close(exec->input);
	close(0);
	dup2(saved[0], 0);
	close(saved[0]);
	if (data->status != 0)
		exit(EXECUTION_FAILED);
	exit(SUCCESSFUL_FINISH);
}

void				execute_child(int (*func)(t_exec *, t_data *), \
													t_exec *exec, t_data *data)
{
	int				stream;
	int				saved[2];

	saved[0] = dup(0);
	if (exec->input != 0)
		dup2(exec->input, 0);
	saved[1] = dup(STD_OUTPUT);
	data->status = 0;
	stream = 0;
	if (exec->output != 1)
	{
		stream = dup2(exec->output, STD_OUTPUT);
		if (stream < 0)
			exit(EXECUTION_FAILED);
	}
	if (!exec->is_func)
	{
		data->status = func(exec, data);
		ft_putnbr_fd(data->status, 1);
	}
	else
		exec_own_child(func, exec, data, saved);
}

static int			execute_func(int (*func)(t_exec *, t_data *), \
									t_exec **exec, t_data *data, int index)
{
	char		*ito;

	ito = NULL;
	data->status = 0;
	if (is_parent(func))
		data->status = func(exec[index], data);
	else
		try_to_execute(func, exec, data, index);
	if (ito)
		free(ito);
	if (data->status != 0)
		return (EXECUTION_FAILED);
	return (SUCCESSFUL_FINISH);
}

static void			*detect_func(const char *pth)
{
	if (*pth == '/' || *pth == '.')
		return (&exec_sys_func);
	if (ft_strmatch(pth, "echo"))
		return (&echo);
	else if (ft_strmatch(pth, "cd"))
		return (&cd);
	else if (ft_strmatch(pth, "pwd"))
		return (&pwd);
	else if (ft_strmatch(pth, "export"))
		return (&own_export);
	else if (ft_strmatch(pth, "unset"))
		return (&unset);
	else if (ft_strmatch(pth, "env"))
		return (&env);
	else if (ft_strmatch(pth, "exit"))
		return (&own_exit);
	return (NULL);
}

int					execute(t_exec **exec, t_data *data)
{
	size_t		index;
	void		*func_ptr;
	int			save_inp_fd;

	save_inp_fd = dup(0);
	index = 0;
	while (exec[index] && data->status != EXECUTION_FAILED)
	{
		if (ft_strncmp(exec[index]->exec_path, "(empty)", 8) == 0)
		{
			index++;
			continue;
		}
		func_ptr = detect_func((const char *)exec[index]->exec_path);
		if (!func_ptr)
			debug_exit();
		data->status = execute_func(func_ptr, exec, data, index);
		if (data->status == 130 || data->status == 131)
			break ;
		index++;
	}
	dup2(save_inp_fd, 0);
	close(save_inp_fd);
	return (data->status);
}
