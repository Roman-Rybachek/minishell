/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 03:34:06 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/27 17:08:34 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				set_output(t_exec *cmd_exec, char **token, int i)
{
	if (cmd_exec->output > 1)
	{
		write(cmd_exec->output, "\0", 1);
		close(cmd_exec->output);
	}
	if (token[i - 1][1] == '>')
		cmd_exec->output = open(token[i], O_CREAT | O_WRONLY | \
										O_APPEND, S_IRWXU | S_IROTH);
	else
		cmd_exec->output = open(token[i], O_CREAT | O_WRONLY | O_TRUNC, \
													S_IRWXU | S_IROTH);
	if (!cmd_exec->output)
		return (0);
	return (1);
}

t_exec			*cmd_exec_init(void)
{
	t_exec		*cmd_exec;

	cmd_exec = malloc(sizeof(t_exec));
	cmd_exec->output = 1;
	cmd_exec->input = 0;
	cmd_exec->exec_path = NULL;
	cmd_exec->args = NULL;
	cmd_exec->is_func = 0;
	cmd_exec->argc = 0;
	return (cmd_exec);
}

void			clr_t_exec(t_exec **all_exec)
{
	t_exec	**tmp;

	tmp = all_exec;
	while (all_exec && *all_exec)
	{
		if ((*all_exec)->exec_path)
			free((*all_exec)->exec_path);
		if ((*all_exec)->args)
			ft_clr_darray((*all_exec)->args);
		if ((*all_exec)->input > 0)
			close((*all_exec)->input);
		if ((*all_exec)->output > 1)
			close((*all_exec)->output);
		free(*all_exec);
		all_exec++;
	}
	free(tmp);
}

int				choose_input_token(t_exec *cmd_exec, char **token, int i)
{
	if (!set_input(cmd_exec, token[i]))
		return (0);
	return (1);
}
