/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_exam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:28:16 by casteria          #+#    #+#             */
/*   Updated: 2020/10/07 15:28:37 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_strlen_1(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char		*ft_strjoin_1(char *s1, char *s2)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen_1(s1) + ft_strlen_1(s2) + 1;
	i = 0;
	new_str = (char *)malloc(len * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1 && *s1)
		new_str[i++] = *s1++;
	while (s2 && *s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}

int			get_next_line_exam(char **line)
{
	char	buf[2];
	char	*temp;
	int		was_read;

	*line = (char *)malloc(sizeof(char));
	*line[0] = '\0';
	while (1)
	{
		if (!(was_read = read(0, buf, 1)) && !*line[0])
			break ;
		buf[1] = '\0';
		if (buf[0] == '\n')
			break ;
		else
		{
			temp = *line;
			*line = ft_strjoin_1(temp, buf);
			free(temp);
			if (!*line)
				return (-1);
		}
	}
	return (was_read);
}
