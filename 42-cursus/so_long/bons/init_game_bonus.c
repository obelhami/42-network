/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:44:35 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/13 03:38:37 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_game(t_data *game_data)
{
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx, game_data->width * 50,
			game_data->height * 50, "so_long");
	load_images(game_data);
	put_image(game_data);
	p_player_count_c(game_data);
	mlx_hook(game_data->win, 2, 2, key_hook, game_data);
	mlx_hook(game_data->win, 17, 0, dbl_free2, game_data);
	game_data->anima_frame = -1;
	mlx_loop_hook(game_data->mlx, move_enemy_bonus, game_data);
	mlx_loop(game_data->mlx);
}
