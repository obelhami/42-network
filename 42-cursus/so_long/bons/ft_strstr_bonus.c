/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:13:06 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/13 03:35:23 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	ft_strstr(char *str, char *to_find)
{
	int	j;
	int	i;

	if (!to_find || !str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (!to_find[j] && !str[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
