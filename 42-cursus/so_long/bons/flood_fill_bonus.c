/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:38:28 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/17 15:07:31 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill_bonus(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'N')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	flood_fill_bonus(map, y + 1, x);
	flood_fill_bonus(map, y - 1, x);
	flood_fill_bonus(map, y, x + 1);
	flood_fill_bonus(map, y, x - 1);
}

void	check_flood_fill_bonus(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				write(1, "Error: the map invalid\n", 23);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
