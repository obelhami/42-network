/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:45:24 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/18 18:27:04 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_get_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	size_read;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size_read = 1;
	while (!gnl_strchr(line, '\n') && size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[size_read] = '\0';
		line = gnl_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_get_next_line(char *line)
{
	char	*next;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	next = (char *)malloc(i + 2);
	if (!next)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		next[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		next[i] = line[i];
		i++;
	}
	next[i] = '\0';
	return (next);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	newline = (char *)malloc((gnl_strlen(line) - i) + 1);
	if (!newline)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		newline[j++] = line[i++];
	newline[j] = '\0';
	free(line);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_get_line(line, fd);
	if (!line)
		return (NULL);
	next_line = ft_get_next_line(line);
	line = new_line(line);
	return (next_line);
}
