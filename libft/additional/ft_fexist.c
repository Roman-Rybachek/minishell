/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fexist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:29:35 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/15 04:30:10 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fexist(char *path_to_file)
{
	int		fd;

	fd = open(path_to_file, O_RDONLY);
	if (fd > 0)
		close(fd);
	if (fd < 0)
		return (0);
	else
		return (1);
}
