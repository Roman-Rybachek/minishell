/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:03:17 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/08 20:24:44 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

extern t_data g_cmd;

static void	handle_sigint(int signal)
{
	ft_printf("\n");
	if (g_cmd.current_process != 0)
	{
		kill(g_cmd.current_process, signal);
		g_cmd.status = 130;
		set_env("?", "130");
	}
	else
	{
		set_env("?", "1");
		prompt(&g_cmd);
	}
	g_cmd.current_process = 0;
}

static void	handle_sigquit(int signal)
{
	if (g_cmd.current_process != 0)
	{
		kill(g_cmd.current_process, signal);
		g_cmd.status = 131;
		ft_printf("Quit: 3\n");
		set_env("?", "131");
	}
	else
	{
		write(1, "\b\b", 2);
	}
	g_cmd.current_process = 0;
}

void		handle_signals(void)
{
	if (signal(SIGINT, &handle_sigint) == SIG_ERR)
		ft_printf("Set SIGINT error");
	if (signal(SIGQUIT, &handle_sigquit) == SIG_ERR)
		ft_printf("Set SIGQUIT error");
}
