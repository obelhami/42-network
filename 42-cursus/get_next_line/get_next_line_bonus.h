/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:09:41 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/20 16:43:12 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

# ifndef OPEN_FD
#  define OPEN_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_get_next_line(char *line);
char	*ft_get_line(char *line, int fd);
char	*new_line(char *line);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strchr(const char *str, int find);
size_t	ft_strlen(const char *tab);

#endif
