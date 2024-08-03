/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:34:15 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/14 03:03:29 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	check_surrounded_by_wall(t_data *game_data)
{
	int	i;
	int	j;

	i = 0;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (i == 0 || i == game_data->height - 1 || j == 0
				|| j == game_data->width - 1)
			{
				if (game_data->map[i][j] != '1')
				{
					write(1, "Error: the map invalid5\n", 23);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	position_element(int *position, char **map, char element)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == element)
			{
				position[0] = y;
				position[1] = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	dbl_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_map_size(t_data *game_data)
{
	if (game_data->width > 51 || game_data->height > 28)
	{
		write(1, "Error: the map invalid0\n", 23);
		exit(1);
	}
}

void	parsing(t_data *game_data)
{
	check_map_is_rectangle(game_data);
	check_element_bonus(game_data->map);
	check_num_of_elements(game_data);
	check_surrounded_by_wall(game_data);
	check_path(game_data);
	check_map_size(game_data);
}
