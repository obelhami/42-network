/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:07:28 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/22 17:14:31 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	size_read;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size_read = 1;
	while (!ft_strchr(line, '\n') && size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[size_read] = '\0';
		line = ft_strjoin(line, buffer);
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
	newline = (char *)malloc(sizeof(char) * (ft_strlen(line) - i) + 1);
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
	static char	*line[OPEN_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = ft_get_line(line[fd], fd);
	if (!line[fd])
		return (NULL);
	next_line = ft_get_next_line(line[fd]);
	line[fd] = new_line(line[fd]);
	return (next_line);
}
/*
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	const char *file_paths[] = { "file.txt", "file1.txt", "file2.txt" };
	int fds[3] = { -1, -1, -1 };
	for (int i = 0; i < 3; i++)
	{
		int fd = open(file_paths[i], O_RDONLY); 
		if (fd < 0)
		{
			printf("ERROR OPENING THE FILE: %s\n", file_paths[i]);
			return (1);
		}
		fds[i] = fd;
	}

    // Reading lines until there are no more lines
	printf("Read line: %s\n", get_next_line(fds[0]));
	printf("Read line: %s\n", get_next_line(fds[1]));
	printf("Read line: %s\n", get_next_line(fds[2]));
	printf("Read line: %s\n", get_next_line(fds[0]));
	printf("Read line: %s\n", get_next_line(fds[1]));
	printf("Read line: %s\n", get_next_line(fds[2]));
	printf("Read line: %s\n", get_next_line(fds[2]));
	printf("Read line: %s\n", get_next_line(fds[0]));
	printf("Read line: %s\n", get_next_line(fds[1]));
	printf("Read line: %s\n", get_next_line(fds[2]));
	printf("Read line: %s\n", get_next_line(fds[1]));
	printf("Read line: %s\n", get_next_line(fds[0]));

    // Close the file descriptor
	for (int j = 0; j < 3; j++)
		close(fds[j]);

    return 0;
}*/
