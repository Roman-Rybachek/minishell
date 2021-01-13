/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sys_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:39:17 by casteria          #+#    #+#             */
/*   Updated: 2020/10/08 20:24:04 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				exec_sys_func(t_exec *exec, t_data *data)
{
	int			status;

	status = execve(exec->exec_path, exec->args, data->env);
	if (errno == 13)
		status = 126;
	else if (errno == 8)
		status = 2;
	ft_printf("minishell: %s: %s\n", exec->exec_path, strerror(errno));
	exit(status);
}
