/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:31:37 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/20 23:47:50 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct s_buf
{
	int		fd;
	int		pos;
	int		max;
	char	data[BUFFER_SIZE];
}	t_buf;

void	initbuf(int fd, t_buf *buf)
{
	buf->fd = fd;
	buf->max = read(fd, buf->data, BUFFER_SIZE);
	buf->pos = -1;
}

char	readbuf(t_buf *buf)
{
	buf->pos++;
	if (buf->pos == buf->max)
	{
		buf->pos = 0;
		buf->max = read(buf->fd, buf->data, BUFFER_SIZE);
	}
	if (buf->max)
		return (buf->data[buf->pos]);
	return (0);
}

int	slen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

char	*sjoin(char *s, char c)
{
	char	*ret;
	int		len;
	int		i;

	len = slen(s);
	ret = (char *)malloc(len + 2);
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	free(s);
	ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_buf	buf = {.fd = -1};
	char			c;

	if (buf.fd != fd && fd > -1)
		initbuf(fd, &buf);
	line = 0;
	c = readbuf(&buf);
	while (c)
	{
		line = sjoin(line, c);
		if (c == '\n')
			return (line);
		c = readbuf(&buf);
	}
	return (line);
}
