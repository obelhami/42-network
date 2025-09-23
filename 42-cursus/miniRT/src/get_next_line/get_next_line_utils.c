/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:31:52 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/30 00:39:07 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *tab)
{
	size_t	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int find)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != (unsigned char)(find))
	{
		if (!str[i])
			return (0);
		i++;
	}
	return ((char *)(str + i));
}

char	*ft_ft_strjoin(char *s1, char const *s2)
{
	char	*new_string;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = alloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_string = alloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[j++] = s2[i++];
	new_string[j] = 0;
	return (new_string);
}
