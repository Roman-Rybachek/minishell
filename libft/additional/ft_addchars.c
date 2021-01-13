/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:27:24 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/03 18:30:33 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchars(char *line, char c, int count)
{
	char	*tmp;
	int		len;

	while (count--)
	{
		len = ft_strlen(line);
		tmp = line;
		line = (char*)malloc(len + 2);
		ft_memcpy(line, tmp, len);
		line[len] = c;
		line[len + 1] = '\0';
		if (tmp)
			free(tmp);
	}
	return (line);
}
