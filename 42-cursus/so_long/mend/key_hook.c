/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:41:51 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/16 19:50:30 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	print_moves(int *moves)
{
	*moves += 1;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(*moves, 1);
	ft_putstr_fd("\n", 1);
}

void	update_direction(int keycode, t_data *game_data)
{
	if (keycode == KEYUP)
	{
		game_data->dx = 0;
		game_data->dy = -1;
	}
	else if (keycode == KEYDOWN)
	{
		game_data->dx = 0;
		game_data->dy = 1;
	}
	else if (keycode == KEYLEFT)
	{
		game_data->dx = -1;
		game_data->dy = 0;
	}
	else if (keycode == KEYRIGHT)
	{
		game_data->dx = 1;
		game_data->dy = 0;
	}
}

int	key_hook(int keycode, t_data *game_data)
{
	if (keycode == KEYESC)
		dbl_free2(game_data);
	else
	{
		update_direction(keycode, game_data);
		move_player(game_data);
		put_image(game_data);
	}
	return (0);
}
