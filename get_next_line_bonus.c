/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:10:46 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/18 09:56:00 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*ft_line(int fd, char *buf, char *reserve)
{
	int	read_line;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!reserve)
			reserve = ft_strdup("");
		reserve = ft_strjoin(reserve ,buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve[10240];
	char		*buf;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = ft_line(fd, buf, reserve[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (free (reserve[fd]), reserve[fd] = NULL);
	reserve[fd] = ft_take(line);
	return (line);
}
