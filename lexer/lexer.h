/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 09:20:03 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/07 15:33:36 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "shared.h"

int			invalid_input(char *input);
int			lexer(char **input, t_data *cmd);
void		backslash(t_data *cmd, char **p);
void		quote(t_data *cmd, char **p);
void		add_token(t_data *cmd);
void		redirection(t_data *cmd, char **p);
void		double_quote(t_data *cmd, char **p);
void		dquote_backslash(t_data *cmd, char **p);

#endif
