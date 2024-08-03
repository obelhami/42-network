/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:40:20 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/17 15:09:40 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	put_element(t_data *game_data, void *element, int i, int j)
{
	if (element == NULL)
	{
		write(1, "Error: image not found\n", 23);
		exit(1);
	}
	mlx_put_image_to_window(game_data->mlx, game_data->win, element, j * 50, i
		* 50);
}

void	draw_image(t_data *game_data, int i, int j)
{
	mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->ground, j
		* 50, i * 50);
	if (game_data->map[i][j] == '1')
		put_element(game_data, game_data->wall, i, j);
	else if (game_data->map[i][j] == 'P')
		put_element(game_data, game_data->player, i, j);
	else if (game_data->map[i][j] == 'C')
		put_element(game_data, game_data->collectible, i, j);
	else if (game_data->map[i][j] == 'E')
	{
		if (game_data->c_count == 0)
			put_element(game_data, game_data->exit[1], i, j);
		else
			put_element(game_data, game_data->exit[0], i, j);
	}
	else if (game_data->map[i][j] == 'N')
		put_element(game_data, game_data->enemy[game_data->anima_frame], i,
			j);
}

int	put_image(t_data *game_data)
{
	int		i;
	int		j;
	char	*str_moves;

	i = 0;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			draw_image(game_data, i, j);
			j++;
		}
		i++;
	}
	str_moves = ft_itoa(game_data->moves);
	str_moves = ft_strjoin("Moves: ", str_moves);
	mlx_string_put(game_data->mlx, game_data->win, 10, 10, 0xFFFFFF, str_moves);
	free(str_moves);
	return (game_data->dy = 0, game_data->dx = 0, 0);
}
