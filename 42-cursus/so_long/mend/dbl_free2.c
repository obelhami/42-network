/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_free2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:35:27 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/13 03:34:25 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	destory_images(t_data *game_data)
{
	int	i;

	i = 0;
	if (game_data->wall)
		mlx_destroy_image(game_data->mlx, game_data->wall);
	if (game_data->ground)
		mlx_destroy_image(game_data->mlx, game_data->ground);
	if (game_data->player)
		mlx_destroy_image(game_data->mlx, game_data->player);
	if (game_data->collectible)
		mlx_destroy_image(game_data->mlx, game_data->collectible);
	if (game_data->exit[0])
		mlx_destroy_image(game_data->mlx, game_data->exit[0]);
	if (game_data->exit[1])
		mlx_destroy_image(game_data->mlx, game_data->exit[1]);
}

int	dbl_free2(t_data *game_data)
{
	int	i;

	i = 0;
	while (game_data->map[i])
	{
		free(game_data->map[i]);
		i++;
	}
	free(game_data->map);
	destory_images(game_data);
	mlx_destroy_window(game_data->mlx, game_data->win);
	exit(0);
	return (0);
}
