/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 02:40:56 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/26 17:15:58 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern t_data g_cmd;

void			add_arg(t_list **args, char **token, t_exec **cmd_exec, int i)
{
	ft_lstadd_back(args, ft_lstnew(ft_strdup(token[i])));
	(*cmd_exec)->argc++;
}

void			clr_one_t_exec(t_exec **cmd_exec)
{
	if ((*cmd_exec)->exec_path)
		free((*cmd_exec)->exec_path);
	if ((*cmd_exec)->args)
		ft_clr_darray((*cmd_exec)->args);
	free(*cmd_exec);
}

int				check_return_code(void)
{
	char	*code;

	code = get_env(g_cmd.env, "?");
	if (ft_strmatch(code, "127"))
	{
		free(code);
		return (0);
	}
	free(code);
	return (1);
}
