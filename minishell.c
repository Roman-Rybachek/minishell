/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 06:32:57 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 15:38:41 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data g_cmd;

static void		data_init(t_data *cmd, char **env)
{
	cmd->tokens = NULL;
	cmd->str = NULL;
	cmd->env = ft_darray_dup(env);
	cmd->user = get_env(cmd->env, "USER");
	cmd->workdir = get_env(cmd->env, "PWD");
	cmd->status = 1;
	cmd->current_process = 0;
	cmd->count_of_process = 0;
	cmd->clean = NULL;
	cmd->input_clear = NULL;
}

static void		free_bef_exit(char *input)
{
	free(g_cmd.workdir);
	free(g_cmd.user);
	ft_clr_darray(g_cmd.env);
	free(input);
}

int				main(int argc, char **argv, char **env)
{
	char	*input;
	int		gnl_res;

	input = NULL;
	(void)argv;
	data_init(&g_cmd, env);
	set_env("?", "0");
	while (1)
	{
		handle_signals();
		prompt(&g_cmd);
		gnl_res = get_next_line_exam(&input);
		g_cmd.input_clear = input;
		if (!gnl_res && ft_printf("exit\n"))
		{
			free_bef_exit(input);
			exit(0);
		}
		if (*input && *input != '\0')
			lexer(&input, &g_cmd);
		ft_free(input);
	}
	ft_nbr_len(argc);
	return (0);
}
