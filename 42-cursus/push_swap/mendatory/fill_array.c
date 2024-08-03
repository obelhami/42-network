/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:31:22 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/22 13:33:32 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_max_int(char **array)
{
	int			i;
	long		num;

	i = 0;
	while (array[i])
	{
		if (ft_strlen(array[i]) - count_string(array[i]) > 11)
		{
			ft_free(array);
			write(2, "Error\n", 6);
			exit(1);
		}
		num = ft_atolong(array[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			ft_free(array);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	fill_array(char **array, char **split, int j, int x)
{
	array[x] = ft_strdup(split[j]);
	if (array[x] == NULL)
	{
		ft_free(array);
		ft_free(split);
		write(2, "Error7\n", 6);
		exit(1);
	}
}
