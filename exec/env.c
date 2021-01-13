/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:40:32 by casteria          #+#    #+#             */
/*   Updated: 2020/09/29 16:31:14 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				env(t_exec *exec, t_data *data)
{
	size_t		index;
	char		**splited;

	(void)exec;
	splited = NULL;
	index = 0;
	while (data->env[index])
	{
		if (!ft_strmatch(data->env[index], "1=1") && \
						ft_strnstr(data->env[index], "=", INT_MAX))
		{
			splited = ft_split(data->env[index], '=');
			if (ft_strncmp(splited[0], "?", 2))
			{
				ft_putstr_fd(data->env[index], STD_OUTPUT);
				ft_putchar_fd('\n', STD_OUTPUT);
			}
			ft_clr_darray(splited);
			splited = NULL;
		}
		index++;
	}
	return (SUCCESSFUL_FINISH);
}
