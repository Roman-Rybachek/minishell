/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:29:24 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 11:27:22 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>

# define RED "\033[1;31m"
# define WHITE "\033[0;37m"
# define WHITE1 "\033[1;37m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"
# define CYAN "\033[1;36m"
# define SUCCESSFUL_FINISH 0
# define EXECUTION_FAILED -1
# define MAX_DIR_LENGTH 1024

# define ERROR "minishell: syntax error near unexpected token"

typedef struct	s_exec
{
	char		*exec_path;
	int			is_func;
	char		**args;
	int			argc;
	int			input;
	int			output;
	pid_t		pid;
}				t_exec;

typedef struct	s_data
{
	pid_t		current_process;
	t_list		*tokens;
	char		*str;
	char		**env;
	char		*workdir;
	char		*user;
	int			status;
	int			pipe[2];
	int			count_of_process;
	void		*clean;
	void		*clean2;
	char		*input_clear;
}				t_data;

int				parser(t_data *cmd);
char			*get_env(char **env, char *str);
void			prompt(t_data *data);
int				execute(t_exec **exec, t_data *data);
void			free_all(t_data *cmd, t_exec *exec_cmd);
void			handle_signals();
void			change_env(char *what, char *new1, char **env);
int				set_env(char *name, char *value);
void			rm_env(char **envs, char *str);
void			env_substitute(t_data *cmd, char **p);
void			clr_t_exec(t_exec **all_exec);

#endif
