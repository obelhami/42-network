/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:34:10 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/13 03:36:47 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

char	**get_map(int fd)
{
	char	**map;
	char	*f_map;
	char	*ptr;

	f_map = get_next_line(fd);
	if (f_map == NULL)
	{
		write(1, "Error: the map is empty\n", 24);
		exit(1);
	}
	while (f_map != NULL)
	{
		if (f_map[0] == '\n')
		{
			write(1, "Error: the map has an empty line\n", 34);
			exit(1);
		}
		ptr = gnl_strjoin(ptr, f_map);
		free(f_map);
		f_map = get_next_line(fd);
	}
	map = ft_split(ptr, '\n');
	free(ptr);
	return (map);
}
