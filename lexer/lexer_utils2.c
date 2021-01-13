/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:31:52 by casteria          #+#    #+#             */
/*   Updated: 2020/10/07 15:35:46 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		dquote_backslash(t_data *cmd, char **p)
{
	if (*(*p + 1) && !ft_strchr("$\\\"", *(*p + 1)))
		cmd->str = ft_addchars(cmd->str, '\\', 1);
	else
	{
		*p += 1;
		if (**p)
			cmd->str = ft_addchars(cmd->str, **p, 1);
	}
}
