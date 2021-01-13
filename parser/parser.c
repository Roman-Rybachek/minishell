/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 21:56:33 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 11:13:10 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern t_data g_cmd;

static int			set_exec_path(t_exec *cmd_exec, \
			char *token, t_data *cmd, t_list **args)
{
	if (*token == '.' || *token == '/')
		check_program_path(cmd_exec, token);
	else if (finding_in_our_func(cmd_exec, token))
		cmd_exec->is_func = 1;
	else if (finding_in_system(cmd_exec, token, cmd))
		cmd_exec->is_func = 0;
	else
	{
		ft_printf("minishell: %s: command not found\n", token);
		set_env("?", "127");
		return (0);
	}
	if (cmd_exec->exec_path && (cmd_exec->argc += 1))
		ft_lstadd_back(args, ft_lstnew(ft_strdup(cmd_exec->exec_path)));
	return (1);
}

static int			switch_case(char **token, t_exec **cmd_exec, \
										t_list **args, int *i)
{
	if (token[*i][0] == '<')
	{
		if (!choose_input_token((*cmd_exec), token, ++(*i)))
			return (0);
	}
	else if (token[*i][0] == '>')
		set_output((*cmd_exec), token, ++(*i));
	else if (!(*cmd_exec)->exec_path)
	{
		if (!set_exec_path((*cmd_exec), token[*i], &g_cmd, args))
			return (0);
	}
	else
		add_arg(args, token, cmd_exec, *i);
	if (!token[*i + 1] && !(*cmd_exec)->exec_path)
		(*cmd_exec)->exec_path = ft_strdup("(empty)");
	return (1);
}

static t_exec		*validaty_cmd(char **token)
{
	t_exec	*cmd_exec;
	t_list	*args;
	int		i;

	args = NULL;
	i = 0;
	cmd_exec = cmd_exec_init();
	while (token && token[i])
	{
		if (!switch_case(token, &cmd_exec, &args, &i))
		{
			if (cmd_exec)
				clr_one_t_exec(&cmd_exec);
			ft_lstclear(&args, free);
			return (NULL);
		}
		i++;
	}
	cmd_exec->args = ft_lst_to_darray(args);
	ft_lstclear(&args, NULL);
	return (cmd_exec);
}

static int			t_array_cycle(char ***cmd_arr, t_data *cmd)
{
	int		i;
	t_exec	**all_exec;
	int		t_len;

	t_len = ft_3array_len(cmd_arr);
	if (!(all_exec = malloc(sizeof(t_exec*) * (t_len + 1))))
		return (-1);
	all_exec[t_len] = 0;
	i = 0;
	while (cmd_arr && cmd_arr[i] && *cmd_arr[i])
	{
		all_exec[i] = validaty_cmd(cmd_arr[i]);
		if (!all_exec[i])
		{
			clr_t_exec(all_exec);
			return (0);
		}
		i++;
	}
	cmd->count_of_process = i;
	cmd->clean = &all_exec;
	execute(all_exec, cmd);
	cmd->count_of_process = 0;
	clr_t_exec(all_exec);
	return (1);
}

int					parser(t_data *cmd)
{
	char	**t_arr;
	char	***cmd_arr;

	t_arr = ft_lst_to_darray(cmd->tokens);
	cmd_arr = ft_darray_split(t_arr, "|");
	ft_lstclear(&cmd->tokens, NULL);
	ft_clr_darray(t_arr);
	cmd->clean2 = cmd_arr;
	t_array_cycle(cmd_arr, cmd);
	ft_3array_clr(cmd_arr);
	return (1);
}
