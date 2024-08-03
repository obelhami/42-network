/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:57:12 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/17 15:08:21 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update(t_data *game_data)
{
	if (game_data->anima_delay == 10)
	{
		game_data->anima_frame++;
		if (game_data->anima_frame == 7)
			game_data->anima_frame = 0;
		game_data->anima_delay = 0;
	}
	game_data->anima_delay++;
}

int	move_enemy_bonus(t_data *game_data)
{
	update(game_data);
	put_image(game_data);
	return (0);
}
