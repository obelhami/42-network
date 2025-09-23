/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:22:23 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/30 00:40:16 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	size_read;

	buffer = (char *)alloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size_read = 1;
	while (!ft_strchr(line, '\n') && size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			garbage_collector();
		}
		buffer[size_read] = '\0';
		line = ft_ft_strjoin(line, buffer);
	}
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
	next = (char *)alloc(i + 2);
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
		return (NULL);
	}
	newline = (char *)alloc((ft_strlen(line) - i) + 1);
	if (!newline)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		newline[j++] = line[i++];
	newline[j] = '\0';
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
/*
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd; // File descriptor
    char *line;

    // Open a file (change "file.txt" to your file's name)
    fd = open("file.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening the file");
        return 1;
    }

    // Reading lines until there are no more lines
    while ((line = get_next_line(fd)) != NULL) {
        printf("Read line: %s\n", line);
        free(line); // Free the line allocated by get_next_line
    }

    // Close the file descriptor
    close(fd);

    return 0;
}*/
