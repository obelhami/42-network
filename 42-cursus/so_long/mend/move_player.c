/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:34:16 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/16 19:59:54 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	handle_interaction(t_data *game_data)
{
	if (game_data->map[game_data->p_y + game_data->dy][game_data->p_x
		+ game_data->dx] == 'C')
	{
		game_data->map[game_data->p_y + game_data->dy][game_data->p_x
			+ game_data->dx] = '0';
		game_data->c_count--;
	}
	else if (game_data->map[game_data->p_y + game_data->dy][game_data->p_x
		+ game_data->dx] == 'E')
	{
		if (game_data->c_count == 0)
			dbl_free2(game_data);
	}
}

void	move_player(t_data *game_data)
{
	if (game_data->map[game_data->p_y + game_data->dy][game_data->p_x
		+ game_data->dx] == '1')
		return ;
	handle_interaction(game_data);
	if (game_data->map[game_data->p_y + game_data->dy][game_data->p_x
		+ game_data->dx] == '0' || game_data->map[game_data->p_y
		+ game_data->dy][game_data->p_x + game_data->dx] == 'C')
	{
		swap_char(&game_data->map[game_data->p_y][game_data->p_x],
			&game_data->map[game_data->p_y + game_data->dy][game_data->p_x
			+ game_data->dx]);
		game_data->p_x += game_data->dx;
		game_data->p_y += game_data->dy;
		print_moves(&game_data->moves);
	}
}
