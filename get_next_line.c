/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:33:26 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/18 08:56:05 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_take(char *line)
{
	size_t	count;
	char	*reserve;

	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	if (line[count] == '\0')
		return (0);
	reserve = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*reserve == '\0')
	{
		free(reserve);
		reserve = NULL;
	}
	line[count + 1] = '\0';
	return (reserve);
}

static char	*ft_lineup(int fd, char *buf, char *reserve)
{
	int		read_line;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!reserve)
			reserve = ft_strdup("");
		reserve = ft_strjoin(reserve, buf);
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = ft_lineup(fd, buf, reserve);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(reserve);
		return (reserve = NULL);
	}
		reserve = ft_take(line);
	return (line);
}
