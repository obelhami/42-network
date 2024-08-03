/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:40:20 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/13 03:49:19 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_exit(t_data *game_data, int i, int j)
{
	if (game_data->c_count == 0)
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->exit[1], j * 50, i * 50);
	else
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->exit[0], j * 50, i * 50);
}

void	put_collectible(t_data *game_data, int i, int j)
{
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->collectible, j * 50, i * 50);
}

void	put_player(t_data *game_data, int i, int j)
{
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->player, j * 50, i * 50);
}

void	put_wall(t_data *game_data, int i, int j)
{
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->wall, j * 50, i * 50);
}

int	put_image(t_data *game_data)
{
	int	i;
	int	j;

	i = 0;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			mlx_put_image_to_window(game_data->mlx, game_data->win,
				game_data->ground, j * 50, i * 50);
			if (game_data->map[i][j] == '1')
				put_wall(game_data, i, j);
			else if (game_data->map[i][j] == 'P')
				put_player(game_data, i, j);
			else if (game_data->map[i][j] == 'C')
				put_collectible(game_data, i, j);
			else if (game_data->map[i][j] == 'E')
				put_exit(game_data, i, j);
			j++;
		}
		i++;
	}
	return (game_data->dy = 0, game_data->dx = 0, 0);
}
