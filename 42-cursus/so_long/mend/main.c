/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:34:21 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/13 03:40:07 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	game_data;

	if (argc != 2)
	{
		write(1, "Error: argument must be one\n", 28);
		exit(1);
	}
	if (!(ft_strstr(argv[1], ".ber")))
	{
		write(1, "Error: the argument must be finish with .ber\n", 45);
		exit(1);
	}
	ft_memset(&game_data, 0, sizeof(t_data));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error: No files shall be created\n", 33);
		exit(1);
	}
	game_data.map = get_map(fd);
	parsing(&game_data);
	close(fd);
	init_game(&game_data);
	return (0);
}
