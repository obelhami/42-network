/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:47:07 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/13 03:41:43 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	p_player_count_c(t_data *game_data)
{
	int	i;
	int	j;

	i = 0;
	game_data->c_count = 0;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (game_data->map[i][j] == 'P')
			{
				game_data->p_x = j;
				game_data->p_y = i;
			}
			if (game_data->map[i][j] == 'C')
				game_data->c_count++;
			j++;
		}
		i++;
	}
}
