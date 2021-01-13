/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 21:57:13 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 11:08:07 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "shared.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>

int			check_return_code(void);
int			check_program_path(t_exec *cmd_exec, char *token);
int			finding_in_system(t_exec *cmd_exec, char *token, t_data *cmd);
int			finding_in_our_func(t_exec *cmd_exec, char *token);
int			set_input(t_exec *cmd_exec, char *token);
int			set_output(t_exec *cmd_exec, char **token, int i);
t_exec		*cmd_exec_init();
int			choose_input_token(t_exec *cmd_exec, char **token, int i);
void		add_arg(t_list **args, char **token, t_exec **cmd_exec, int i);
void		clr_one_t_exec(t_exec **cmd_exec);

#endif
