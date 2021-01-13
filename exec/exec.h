/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:35:16 by casteria          #+#    #+#             */
/*   Updated: 2020/10/07 15:16:15 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "shared.h"
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define STD_OUTPUT 1
# define STD_INPUT 0
# define STD_ERR 2
# define NOT_FOUND -2

int				execute(t_exec **exec, t_data *data);
int				echo(t_exec *exec, t_data *data);
int				cd(t_exec *exec, t_data *data);
int				pwd(void);
int				own_export(t_exec *exec, t_data *data);
int				unset(t_exec *exec, t_data *data);
int				env(t_exec *exec, t_data *data);
int				own_exit(t_exec *exec, t_data *data);
int				exec_sys_func(t_exec *exec, t_data *data);
void			debug_exit();
void			command_not_found(const char *cmd);
int				is_parent(int (*func)(t_exec *, t_data *));
void			execute_child(int (*func)(t_exec *, t_data *), \
												t_exec *exec, t_data *data);
void			try_to_execute(int (*func)(t_exec *, t_data *), \
									t_exec **exec, t_data *data, int index);
int				parse_new_var(char *env_name);
int				return_error(char *new_env, char **splited, t_data *data);
int				do_export(t_exec *exec, t_data *data, size_t index);
void			free_before_exit(t_data *data, char *free_get_env);
int				return_too_many_args(char *free_get_env);

#endif
