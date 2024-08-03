/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:31:06 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/17 15:06:17 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	check_element_bonus(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'N')
			{
				write(1, "Error: Wrong element exist\n", 27);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	count_element(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_num_of_elements(t_data *game_data)
{
	int	count_p;
	int	count_e;
	int	count_c;

	count_p = count_element(game_data->map, 'P');
	count_e = count_element(game_data->map, 'E');
	count_c = count_element(game_data->map, 'C');
	if (count_p != 1 || count_e != 1 || count_c == 0)
	{
		write(1, "Error: The number of element is wrong\n", 39);
		exit(1);
	}
}
