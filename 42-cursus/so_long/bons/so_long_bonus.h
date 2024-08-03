/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:29:37 by obelhami          #+#    #+#             */
/*   Updated: 2024/03/14 03:29:38 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define KEYESC 53
# define KEYUP 13
# define KEYDOWN 1
# define KEYLEFT 0
# define KEYRIGHT 2

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*wall;
	void	*ground;
	void	*player;
	void	*collectible;
	void	*exit[2];
	void	*enemy[7];
	int		p_x;
	int		p_y;
	int		c_count;
	int		dx;
	int		dy;
	int		moves;
	int		anima_delay;
	int		anima_frame;
}			t_data;

void		check_element_bonus(char **map);
void		flood_fill_bonus(char **map, int y, int x);
void		check_flood_fill_bonus(char **map);
char		**get_map(int fd);
void		swap_char(char *a, char *b);
void		dbl_free(char **str);
int			move_enemy_bonus(t_data *game_data);
void		*load_image(char *path, t_data *game_data);
int			key_hook(int keycode, t_data *game_data);
int			put_image(t_data *game_data);
void		move_player(t_data *game_data);
void		p_player_count_c(t_data *game_data);
void		load_images(t_data *game_data);
int			ft_strstr(char *str, char *to_find);
void		parsing(t_data *game_data);
void		init_game(t_data *game_data);
void		move_player(t_data *game_data);
void		swap_char(char *a, char *b);
int			dbl_free2(t_data *game_data);
void		check_map_is_rectangle(t_data *game_data);
void		check_path(t_data *game_data);
int			count_element(char **map, char c);
void		check_num_of_elements(t_data *game_data);
void		check_surrounded_by_wall(t_data *game_data);
void		position_element(int *position, char **map, char element);
void		check_map_size(t_data *game_data);
void		put_exit(t_data *game_data, int i, int j);
void		put_collectible(t_data *game_data, int i, int j);
void		put_player(t_data *game_data, int i, int j);
void		put_wall(t_data *game_data, int i, int j);
void		count_moves(int *moves);

#endif