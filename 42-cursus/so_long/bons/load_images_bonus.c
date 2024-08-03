/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:26:18 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/17 15:08:08 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	*load_image(char *path, t_data *game_data)
{
	int		i;
	int		j;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(game_data->mlx, path, &i, &j);
	if (!ptr)
	{
		write(1, "Error: ", 7);
		write(1, "Image not found\n", 16);
		dbl_free2(game_data);
	}
	return (ptr);
}

void	load_images(t_data *game_data)
{
	game_data->wall = load_image("./img/wall2.xpm", game_data);
	game_data->ground = load_image("./img/ground.xpm", game_data);
	game_data->player = load_image("./img/player.xpm", game_data);
	game_data->collectible = load_image("./img/gold1.xpm", game_data);
	game_data->exit[0] = load_image("./img/doorinactive.xpm", game_data);
	game_data->exit[1] = load_image("./img/dooractive1.xpm", game_data);
	game_data->enemy[0] = load_image("./img/Fire1.xpm", game_data);
	game_data->enemy[1] = load_image("./img/Fire2.xpm", game_data);
	game_data->enemy[2] = load_image("./img/Fire3.xpm", game_data);
	game_data->enemy[3] = load_image("./img/Fire4.xpm", game_data);
	game_data->enemy[4] = load_image("./img/Fire5.xpm", game_data);
	game_data->enemy[5] = load_image("./img/Fire6.xpm", game_data);
	game_data->enemy[6] = load_image("./img/Fire7.xpm", game_data);
}
