/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:41:50 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/06 17:54:43 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		free_all(char **immrtal_buf, char **line)
{
	if (*immrtal_buf != NULL)
		free(*immrtal_buf);
	if (*line != NULL)
		free(*line);
	return (-1);
}

static int		found_line(char **immrtal_buf, char *buf, char **line)
{
	size_t len;
	size_t im_len;

	im_len = ft_strlen(*immrtal_buf);
	len = ft_strchr(buf, '\n') - buf;
	if (*immrtal_buf != NULL)
		len += im_len;
	if (!(*line = (char*)malloc(sizeof(char) * (len + 1))))
		return (free_all(immrtal_buf, line));
	if (*immrtal_buf != NULL)
	{
		*line += ft_strlcpy(*line, *immrtal_buf, im_len + 1);
		len -= im_len;
	}
	ft_strlcpy(*line, buf, len + 1);
	if (*immrtal_buf != NULL)
	{
		*line -= im_len;
		free(*immrtal_buf);
	}
	buf += len + 1;
	if (!(*immrtal_buf = (char*)malloc(ft_strlen(buf) + 1)))
		return (free_all(immrtal_buf, line));
	ft_strlcpy(*immrtal_buf, buf, ft_strlen(buf) + 1);
	return (1);
}

static int		immrtl_buf_has_line(char **immrtl_buf, char **line)
{
	size_t	len;
	char	*tmp;
	char	*line_to_free;

	if (ft_strchr(*immrtl_buf, '\n'))
	{
		len = ft_strchr(*immrtl_buf, '\n') - *immrtl_buf;
		if (!(*line = (char*)malloc((len + 1))))
			return (free_all(immrtl_buf, line));
		ft_strlcpy(*line, *immrtl_buf, len + 1);
		if (!(tmp = (char*)malloc((ft_strlen(*immrtl_buf) - len))))
			return (free_all(immrtl_buf, line));
		ft_strlcpy(tmp, *immrtl_buf + len + 1, ft_strlen(*immrtl_buf) - len);
		free(*immrtl_buf);
		*immrtl_buf = tmp;
		return (1);
	}
	line_to_free = *line;
	if (!(*line = (char*)malloc((ft_strlen(*immrtl_buf) + 1))))
		return (free_all(immrtl_buf, line));
	ft_strlcpy(*line, *immrtl_buf, ft_strlen(*immrtl_buf) + 1);
	free(*immrtl_buf);
	*immrtl_buf = NULL;
	free(line_to_free);
	return (0);
}

static int		refresh_immrtl_buf(char **immrtl_buf, char *buf, char **line)
{
	size_t		len;
	size_t		im_len;
	char		*tmp;

	im_len = ft_strlen(*immrtl_buf);
	len = ft_strlen(buf);
	if (*immrtl_buf != NULL)
		len += im_len;
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (free_all(immrtl_buf, line));
	if (*immrtl_buf != NULL)
		tmp += ft_strlcpy(tmp, *immrtl_buf, im_len + 1);
	ft_strlcpy(tmp, buf, ft_strlen(buf) + 1);
	if (*immrtl_buf != NULL)
	{
		tmp -= im_len;
		free(*immrtl_buf);
	}
	*immrtl_buf = tmp;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*immrtl_buf;
	char			buf[BUFFER_SIZE + 1];
	int				got_bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (1)
	{
		if (!((got_bytes = read(fd, buf, BUFFER_SIZE)) > 0))
			break ;
		buf[got_bytes] = '\0';
		if (ft_strchr(buf, '\n'))
			return (found_line(&immrtl_buf, buf, line));
		if (!(refresh_immrtl_buf(&immrtl_buf, buf, line)))
			return (-1);
	}
	if (got_bytes < 0)
		return (-1);
	if (!(*line = (char*)malloc(1)))
		return (free_all(&immrtl_buf, line));
	**line = '\0';
	if (immrtl_buf != NULL && got_bytes == 0)
		return (immrtl_buf_has_line(&immrtl_buf, line));
	return (0);
}
