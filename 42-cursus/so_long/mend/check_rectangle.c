/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:51:19 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/14 03:02:21 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_map_is_rectangle(t_data *game_data)
{
	int	i;

	game_data->width = ft_strlen(game_data->map[0]);
	game_data->height = 1;
	i = 0;
	while (game_data->map[game_data->height])
	{
		i = ft_strlen(game_data->map[game_data->height]);
		if (game_data->width != i)
		{
			write(1, "Error: the map invalid\n", 23);
			exit(1);
		}
		game_data->height++;
	}
}
