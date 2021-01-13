/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 00:52:38 by casteria          #+#    #+#             */
/*   Updated: 2020/09/24 16:05:47 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			pwd(void)
{
	char	cwd[MAX_DIR_LENGTH];
	size_t	path_length;

	ft_bzero(cwd, MAX_DIR_LENGTH);
	getcwd(cwd, INT_MAX);
	if (cwd[0] == '\0')
		return (EXECUTION_FAILED);
	path_length = ft_strlen(cwd);
	write(STD_OUTPUT, cwd, path_length);
	write(STD_OUTPUT, "\n", 1);
	return (SUCCESSFUL_FINISH);
}
