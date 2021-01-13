/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 04:11:22 by casteria          #+#    #+#             */
/*   Updated: 2020/09/24 16:06:40 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				echo(t_exec *exec, t_data *data)
{
	size_t		index;

	index = 1;
	while (exec->args && exec->args[index])
	{
		if (!ft_strncmp("-n", exec->args[index], INT_MAX) && index == 1)
		{
			index++;
			continue;
		}
		ft_putstr_fd(exec->args[index++], STD_OUTPUT);
		if ((int)index != exec->argc)
			write(STD_OUTPUT, " ", 1);
	}
	if (!(exec->args && exec->args[1] && !ft_strncmp(exec->args[1], \
															"-n", INT_MAX)))
		ft_putchar_fd('\n', STD_OUTPUT);
	(void)exec;
	(void)data;
	return (SUCCESSFUL_FINISH);
}
