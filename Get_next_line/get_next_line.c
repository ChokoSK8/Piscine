/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:21:26 by abrun             #+#    #+#             */
/*   Updated: 2020/12/09 10:38:43 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			get_len_buf(char *buf)
{
	int		len;

	len = 0;
	while (buf[len] != '\n' && buf[len])
		len++;
	return (len);
}

char			*ft_strdup(const char *s1)
{
	size_t			s1_len;
	unsigned char	*dst;
	unsigned int	len;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	len = s1_len;
	if (!(dst = malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	while (s1_len--)
		*dst++ = *s1++;
	*dst = '\0';
	return ((char *)dst - len);
}

int				fill_line(char *buf, char **line)
{
	size_t			line_bis_len;
	size_t			buf_len;
	char			*line_bis;
	unsigned int	counter;

	counter = 0;
	buf_len = get_len_buf(buf);
	line_bis_len = ft_strlen(*line);
	if (!(line_bis = ft_strdup(*line)))
		return (0);
	free(*line);
	if (!(*line = malloc(buf_len + line_bis_len + 1)))
	{
		free(line_bis);
		return (0);
	}
	while (*line_bis)
		line[0][counter++] = *line_bis++;
	while (*buf && *buf != '\n')
		line[0][counter++] = *buf++;
	if (line[0])
		line[0][counter] = '\0';
	free(line_bis - line_bis_len);
	return (1);
}

char			*get_buf(int fd, int *ret, char *buf)
{
	if (!buf)
	{
		if (!(buf = malloc(BUFFER_SIZE + 1)))
			return (0);
		*ret = read(fd, buf, BUFFER_SIZE);
		if (*ret < 0)
			return (0);
		buf[*ret] = '\0';
		return (buf);
	}
	else if (!*(buf + get_len_buf(buf)))
	{
		free(buf);
		if (!(buf = malloc(BUFFER_SIZE + 1)))
			return (0);
		*ret = read(fd, buf, BUFFER_SIZE);
		buf[*ret] = '\0';
	}
	return (buf);
}

int				get_next_line(int fd, char **line)
{
	static char			*buf = NULL;
	static int			ret = 2;

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!(*line = malloc(1)))
		return (-1);
	line[0][0] = 0;
	if (buf)
		if (ret <= 0 || !fill_line(buf, line))
			return (-1);
	while ((!buf || *(buf + get_len_buf(buf)) != '\n') && ret > 0)
		if (!(buf = get_buf(fd, &ret, buf)) || !fill_line(buf, line))
			return (-1);
	if (ret <= 0)
	{
		if (buf)
			free(buf);
		return (0);
	}
	if (ret > 0)
		buf = get_new_buf(buf);
	return (ret);
}
