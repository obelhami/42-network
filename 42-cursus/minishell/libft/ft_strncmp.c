/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:45:48 by ybahij            #+#    #+#             */
/*   Updated: 2024/10/02 22:41:55 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp1(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2 || ft_strlen(s1) != n || ft_strlen(s2) != n)
		return (1);
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (s1[i] == s2[i]))
	{
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
