/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:34:14 by casteria          #+#    #+#             */
/*   Updated: 2020/10/07 15:17:21 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		sort_vars(char **env)
{
	size_t		index1;
	size_t		index2;
	char		*buffer;

	index1 = 0;
	while (env[index1 + 1])
	{
		index2 = index1 + 1;
		while (env[index2])
		{
			if (*env[index1] > *env[index2])
			{
				buffer = env[index1];
				env[index1] = env[index2];
				env[index2] = buffer;
			}
			index2++;
		}
		index1++;
	}
}

static void		print_vars(t_data *data)
{
	size_t		index;
	char		**splited;
	char		*env;

	index = 0;
	splited = NULL;
	sort_vars(data->env);
	while (data->env[index])
	{
		if (!ft_strmatch(data->env[index], "1=1"))
		{
			env = ft_strchr(data->env[index], '=');
			splited = ft_split(data->env[index], '=');
			if (ft_strncmp(splited[0], "?", 2))
				ft_printf("declare -x %s", splited[0]);
			if (env)
				ft_printf("=\"%s\"\n", env + 1);
			else
				ft_printf("\n");
			ft_clr_darray(splited);
			splited = NULL;
		}
		index++;
	}
}

int				parse_new_var(char *env_name)
{
	size_t		index;

	index = 0;
	while (env_name[index])
	{
		if (!ft_isalnum(env_name[index]) && env_name[index] \
				!= '=' && env_name[index] != '_')
			return (0);
		index++;
	}
	return (1);
}

int				own_export(t_exec *exec, t_data *data)
{
	size_t		index;
	int			status;

	index = 1;
	status = 0;
	while (exec->args[index])
	{
		if (do_export(exec, data, index) == 1)
			status = 1;
		index++;
	}
	if (index == 1)
		print_vars(data);
	return (status);
}
