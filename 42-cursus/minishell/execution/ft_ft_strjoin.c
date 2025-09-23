/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:52:21 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:52:23 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_string = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_string == 0)
		return (0);
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
