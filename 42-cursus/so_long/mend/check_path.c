/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:53:32 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/14 03:02:08 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_path(t_data *game_data)
{
	char	**cpy_map;
	int		player_position[2];
	int		i;

	cpy_map = malloc(sizeof(char *) * (game_data->height + 1));
	if (!cpy_map)
	{
		write(1, "Error: malloc failed\n", 21);
		exit(1);
	}
	i = 0;
	while (i < game_data->height)
	{
		cpy_map[i] = ft_strdup(game_data->map[i]);
		i++;
	}
	cpy_map[i] = NULL;
	position_element(player_position, game_data->map, 'P');
	flood_fill(cpy_map, player_position[0], player_position[1]);
	check_flood_fill(cpy_map);
	dbl_free(cpy_map);
}
